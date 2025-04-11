use std::fmt::format;
use serde_json::json;
use reqwest::{Client, Error, Response};
use serde::{Serialize, Deserialize};
use tokio::time::{sleep, Duration};

const URL_POST: &str = "https://chirpstack-api.iotserv.ru/api/devices";
const URL_GET: &str = "https://chirpstack-api.iotserv.ru/api/devices?limit=10&applicationId=9cfc547c-ccfa-4aeb-a9f1-bc73aad24dae";
const APP_ID: &str = "9cfc547c-ccfa-4aeb-a9f1-bc73aad24dae";
const DEVICE_PROF_ID: &str = "a40b2348-93d8-4c8e-85f7-f4dc78f669b5";
const JOIN_EUI : &str = "0000000000000000";
const DESCRIPTION: &str = "Test device from ZAS-021";
const AUTH_TOKEN: &str = "Bearer eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJhdWQiOiJjaGlycHN0YWNrIiwiaXNzIjoiY2hpcnBzdGFjayIsInN1YiI6IjI0MTEyMjMxLWE1ZDMtNGExNC1iYmExLTdjYzg0YjhlMTdmMiIsInR5cCI6ImtleSJ9.f9cieqtMQPxb9691My-rL3TA6FPl-2nP5h14jOEv6iY";
#[derive(Serialize, Deserialize, Debug)]
struct Device {
    applicationId: String,
    description: String,
    devEui: String,
    deviceProfileId: String,
    isDisabled: bool,
    joinEui: String,
    name: String,
    skipFcntCheck: bool,
}

#[derive(Serialize, Deserialize, Debug)]
struct PostBody {
    device: Device,
}

#[derive(Serialize, Deserialize, Debug)]
struct DeviceStatus {
    margin: i32,
    external_power_source: Option<bool>,
    battery_level: Option<i32>,
}

#[derive(Serialize, Deserialize, Debug)]
struct DeviceResponse {
    devEui: String,
    createdAt: String,
    updatedAt: String,
    lastSeenAt: Option<String>,
    name: String,
    description: String,
    deviceProfileId: String,
    deviceProfileName: String,
    deviceStatus: Option<DeviceStatus>,
}

#[derive(Serialize, Deserialize, Debug)]
struct GetResponse {
    totalCount: u32,
    result: Vec<DeviceResponse>,
}



enum Request {
    POST,
    PUT,
    GET,
    DELETE,
}

#[tokio::main]
async fn main() -> Result<(), Error>{
    //вектор для хранения устройств
    let mut vec_devices: Vec<PostBody> = Vec::with_capacity(10);

    //создаём клиента для запросов
    let client = reqwest::Client::new();

    //создаём устройства
    for i in 0..10 {
        let body = create_device(i);
        let response = send_response(&body, &client, Request::POST, AUTH_TOKEN).await?;
        check_response(response, Request::POST).await;
        vec_devices.push(body);
        delay(1).await; //задержка для создания устройства
    }
    delay(2).await;

    // Отправляем GET запрос и обрабатываем ответ
    //сначала написал функцию под POST, а потом ее решил под все запросы адаптировать, но возникла заморочка с обработкой ошибки поэтому пришлось для запросов без тела вставлять заглушку в виде пустой структуры
    let get_response = send_response(&PostBody { device: Device { applicationId: "".to_string(), description: "".to_string(), devEui: "".to_string(), deviceProfileId: "".to_string(), isDisabled: false, joinEui: "".to_string(), name: "".to_string(), skipFcntCheck: false } }, &client, Request::GET, AUTH_TOKEN).await?;
    check_response(get_response, Request::GET).await;
    delay(2).await;

    // Обновляем имя устройства через PUT-запрос
    for device in &vec_devices {
        let updated_body = update_device_name(device);
        let response = send_response(&updated_body, &client, Request::PUT, AUTH_TOKEN).await?;
        check_response(response, Request::PUT).await;
        delay(1).await; // Задержка между обновлениями
    }

    delay(2).await;
    let put_response = send_response(&PostBody { device: Device { applicationId: "".to_string(), description: "".to_string(), devEui: "".to_string(), deviceProfileId: "".to_string(), isDisabled: false, joinEui: "".to_string(), name: "".to_string(), skipFcntCheck: false } }, &client, Request::GET, AUTH_TOKEN).await?;
    check_response(put_response, Request::GET).await;
    delay(2).await;

    
    // Удаляем устройства через DELETE-запрос
    for device in &vec_devices {
        let delete_url = format!("https://chirpstack-api.iotserv.ru/api/devices/{}", device.device.devEui);
        let response = send_response(
            &PostBody {
                device: Device {
                    applicationId: "".to_string(),
                    description: "".to_string(),
                    devEui: device.device.devEui.clone(),
                    deviceProfileId: "".to_string(),
                    isDisabled: false,
                    joinEui: "".to_string(),
                    name: "".to_string(),
                    skipFcntCheck: false,
                },
            },
            &client,
            Request::DELETE,
            AUTH_TOKEN,
        )
            .await?;
        check_response(response, Request::DELETE).await;
        delay(1).await; // Задержка между удалениями
    }

    delay(2).await;
    let del_response = send_response(&PostBody { device: Device { applicationId: "".to_string(), description: "".to_string(), devEui: "".to_string(), deviceProfileId: "".to_string(), isDisabled: false, joinEui: "".to_string(), name: "".to_string(), skipFcntCheck: false } }, &client, Request::GET, AUTH_TOKEN).await?;
    check_response(del_response, Request::GET).await;


    Ok(())
}

// функция создания устройства POST
fn create_device(num: u32) -> PostBody {
    let dev_name = "device_ZAS-021_".to_string() + &num.to_string();
    let dev_eui = "00112".to_string() + &num.to_string() + "33FFAA1101".to_string().as_str();
    let body = PostBody {
        device: Device {
            applicationId: APP_ID.to_string(),
            description: DESCRIPTION.to_string(),
            devEui: dev_eui,
            deviceProfileId: DEVICE_PROF_ID.to_string(),
            isDisabled: false,
            joinEui: JOIN_EUI.to_string(),
            name: dev_name,
            skipFcntCheck: false,
        },
    };
    body
}

async fn send_response(body: &PostBody, client: &Client, request: Request, auth_token: &str) -> Result<Response, Error> {
    // Определяем URL в зависимости от типа запроса
    let url = match request {
        Request::POST => URL_POST,
        Request::GET => URL_GET,
        Request::DELETE => &*{
            // Для DELETE запроса формируем URL с devEui
            format!("https://chirpstack-api.iotserv.ru/api/devices/{}", body.device.devEui)
        },
        Request::PUT => &*{
            // Для PUT-запроса формируем URL с devEui
            format!("https://chirpstack-api.iotserv.ru/api/devices/{}", body.device.devEui)
        }
    };

    // Отправляем запрос в зависимости от типа
    let response = match request {
        Request::POST => {
            client.post(url)
                .header("Authorization", auth_token)
                .header("accept", "application/json")
                .json(&body)
                .send()
                .await?
        }
        Request::GET => {
            client.get(url)
                .header("Authorization", auth_token)
                .header("accept", "application/json")
                .send()
                .await?
        }
        Request::DELETE => {
            client.delete(url)
                .header("Authorization", auth_token)
                .header("accept", "application/json")
                .send()
                .await?
        }
        Request::PUT => {
            client.put(url)
                .header("Authorization", auth_token)
                .header("accept", "application/json")
                .json(&body)
                .send()
                .await?
        }
    };
    Ok(response)
}

async fn check_response(response: Response, request: Request) {
    let request_str = match request {
        Request::POST => "POST",
        Request::PUT => "PUT",
        Request::GET => "GET",
        Request::DELETE => "DELETE",
    };

    if response.status().is_success() {
        match request {
            Request::GET => {
                let response_text = response.text().await.unwrap();
                //println!("Raw response body: {}", response_text);

                // Попытка десериализации
                match serde_json::from_str::<GetResponse>(&response_text) {
                    Ok(get_response) => {
                        // Преобразуем структуру обратно в JSON и выводим красиво
                        let pretty_json = serde_json::to_string_pretty(&get_response).unwrap();
                        println!("{} request successful. Formatted Response:\n{}", request_str, pretty_json);
                    }
                    Err(e) => {
                        println!("Failed to deserialize response: {}", e);
                    }
                }
            }
            _ => {
                let response_text = response.text().await.unwrap();
                println!("{} request successful. Response: {}", request_str, response_text);
            }
        }
    } else {
        let status = response.status();
        let response_text = response.text().await.unwrap();
        println!("{} request failed with status {}. Response: {}", request_str, status, response_text);
    }
}

fn update_device_name(device: &PostBody) -> PostBody {
    PostBody {
        device: Device {
            name: format!("{}_UPDATED", device.device.name),
            applicationId: device.device.applicationId.clone(),
            deviceProfileId: device.device.deviceProfileId.clone(),
            devEui: device.device.devEui.clone(),
            description: device.device.description.clone(),
            isDisabled: device.device.isDisabled,
            joinEui: device.device.joinEui.clone(),
            skipFcntCheck: device.device.skipFcntCheck,
        },
    }
}

async fn delay(t:u64) {
    sleep(Duration::from_secs(t)).await
}

# Laboratory Activity 9: Wi-Fi Manager on ESP32

**Name:** Guido Manfred G. Mejos  
**Assigned Number:** 1115 (`BCA188-ESP32-1115`)  

---

## 1. Practice Tasks Results Table

| # | Task | What to do | What you observe |
| :--- | :--- | :--- | :--- |
| **1** | **Wrong password** | Enter a wrong password on the setup page. | The ESP32 fails to authenticate with the access point, remains disconnected, and reopens the configuration portal (or restarts after the 180-second timeout). |
| **2** | **Reset settings** | Hold the BOOT button for 3 seconds while the board is running. | The Serial Monitor prints the reset confirmation, `wm.resetSettings()` clears the stored Wi-Fi credentials from flash memory, and the board reboots into Access Point mode (`BCA188-ESP32-1115`). |
| **3** | **Change the name** | Change the network name, upload, and check your phone’s Wi-Fi list. | The previous SSID disappears and the newly configured Access Point name (`BCA188-ESP32-1115`) appears in the phone's available Wi-Fi networks list. |
| **4** | **Different network** | Reset the board, then connect to your phone hotspot. | After selecting the phone hotspot on the `192.168.4.1` portal and entering its password, the ESP32 connects to the hotspot and prints a new local IP address in the Serial Monitor. |

---

## 2. Screenshots

### Phone Setup Page (`192.168.4.1`)
<img width="872" height="1216" alt="Lab_9_bca188" src="https://github.com/user-attachments/assets/3b9b9942-0742-4124-8ae5-57e3c2461d74" />


### Serial Monitor Output (Connected State)
<img width="1416" height="752" alt="serialmonitor_lab_9" src="https://github.com/user-attachments/assets/9b936968-c984-4f43-bbb4-af452146a4f8" />

---

## 3. Explanation

**Why did the board connect to a different network without a code change?**  
The `WiFiManager` library stores the Wi-Fi SSID and password in the ESP32's non-volatile flash memory (NVS) through the web portal, allowing the board to load and connect with the updated credentials on boot without modifying or re-uploading the sketch.

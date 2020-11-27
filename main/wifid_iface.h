#define PORT_RECV	67
#define PORT_SEND	68


//Sent if WiFi should connect to an AP
#define CMD_CONNECT 1
//Send if WiFi should scan & return available APs
#define CMD_SCAN 2
//Sent to localhost when wifid should exit (because a new wifid instance is replacing it)
#define CMD_QUIT 256

typedef struct {
	uint32_t cmd;
	union {
		struct {
			char ssid[32];
			char pass[64];
		} connect;
	};
} wifid_cmd_t;

//Received when we're connected and have an IP
#define EV_GOT_IP 1
//Received per scan result
#define EV_SCAN_RES 2
//Received when all scan results are returned
#define EV_SCAN_RES_END 3
//Some error occured
#define EV_ERROR 4
//Received over loopback when another wifid instance replaces this one
#define EV_QUIT CMD_QUIT

typedef struct {
	uint32_t resp;
	union {
		struct {
			uint8_t ip[4];
			uint8_t netmask[4];
			uint8_t gw[4];
			uint8_t nameserver[3][4];
		} connected;
		struct {
			char ssid[32];
			int rssi;
			int authmode;
		} scan_res;
		struct {
			char msg[32];
		} error;
	};
} wifid_event_t;


#ifndef messages
#define messages

#include <Arduino.h>

#define RPT 0
#define CMD 2

typedef struct BaseMessage {
  unsigned char msgType;
} BaseMessage;

typedef struct NodeConfigCommand {
    const unsigned char msgType = CMD + (0 << 2);
	long signature;
	unsigned char newNodeId;
    unsigned char halPins;
    unsigned char dryPins;
    unsigned char vInPins;
    unsigned char features;
} NodeConfigCommand;

typedef struct NodeInfoReport {
    const unsigned char msgType = RPT + (0 << 2);
    short sendErrorCount;
    short startCount;
    short vIn;
} NodeInfoReport;

typedef struct PulseReport {
    const unsigned char msgType = RPT + (1 << 2);
    unsigned char subNode;
    unsigned char newPulses;
} PulseReport;

typedef struct EnvironmentReport {
    const unsigned char msgType = RPT + (2 << 2);
    int temperature;
    int humidity;
    int pressure;
} EnvironmentReport;

struct NodeStartedReport {
    const unsigned char msgType = RPT + (3 << 2);
    unsigned char major;
    unsigned char minor;
    uint8_t signature[8];
    bool needNewNodeId;
};

typedef struct ReadyForProgCommand {
    const unsigned char msgType = RPT + (4 << 2);
} ReadyForProgCommand;

#endif
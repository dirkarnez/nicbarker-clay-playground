#include <iostream>
#define CLAY_IMPLEMENTATION
#include "clay.h"

Clay_LayoutConfig layoutElement = Clay_LayoutConfig { .padding = {5} };

void HandleClayErrors(Clay_ErrorData errorData) {
    printf("%s", errorData.errorText.chars);
}

int main(void) {
    uint64_t totalMemorySize = Clay_MinMemorySize();
    Clay_Arena clayMemory = Clay_CreateArenaWithCapacityAndMemory(totalMemorySize, (char *)malloc(totalMemorySize));
    Clay_Initialize(clayMemory, Clay_Dimensions {1024,768}, Clay_ErrorHandler { HandleClayErrors });
    Clay_BeginLayout();
    CLAY(CLAY_RECTANGLE({ .color = {255,255,255,0} }), CLAY_LAYOUT(layoutElement)) {}
    Clay_EndLayout();
    return 0;
}

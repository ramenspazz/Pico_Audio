#include "main_head.hcc"

#define MAX_BUFFER_SIZE (uint8_t)32

int main(){
    // Choose which PIO instance to use (there are two instances)
    PIO pio = pio0;
    int offset=pio_add_program(pio,&buffer_program);
    uint sm=pio_claim_unused_sm(pio,true);
    buffer_program_init(pio,sm,offset,PICO_AUDIO_I2S_DATA_PIN);
    uint32_t index = 0;

    // create device for audio data output
    auto buffer = AUDIO_DEVICE::audio_device<uint32_t>(MAX_BUFFER_SIZE); 

    while (true)
    {
        buffer.buffer_data_send_to_I2S_pin(sm);
        buffer.buffer_data_push(std::move(uint32_t(10 * std::sin(index/(2*PI)))));
        index++;
        if(index==31){index=0;}
    }
    
}
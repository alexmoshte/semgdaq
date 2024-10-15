README
The semgdaq board is a wearable 6 channel data acquisition unit for capturing surface electromyographic (sEMG) signals from human arm muscles using SJ2-3593D jack connectors while conditioning, digitizing, processing and feature extracting them then transmitting the feature data as vectors to an external AI accelerated board through an SM12B-SRSS IDC connector using 12C and UART communication protocals where AI models are run for various applications including robotic control, muscle signals medical assessment and gesture recognition. The feature vectors are comprised of onset detection, slope sign changes, autoregression coefficients and Short Time Fourier Transform magnitude spectrum data for each segment or window of the signals in real time. This vectors can be used as the basis for further feature extraction on more computationally resourceful hardware where machine lerning algorthms can be employed for descision making in the applications mentioned earlier. The board leverages INA125P instrumentation amplifiers together with filter stages utilizing LM324QT op-amps for conditioning and an STM32G4A1VET6 microcontroller for the digitization, processing, feature extraction and data transmission. Since AI models can only be as good as the data, the design of such a DAQ is necessary to ensure clean, reliable and real-time data for AI applications requiring sEMG feature data. The board also has USB-FS and JTAG to cater for debugging and external flash memory to extend its data storage and processing capability. The power (5V) is fed through a screw terminal and is regulated by two LDK320AM LDO regulators to offer 5V, 3.3V and 1.8V to meet the requirements of various components on the board. Link to the PCB design project can be found on the repo's about. Here, I upload the manufacturing files, the firmware and applications code in C developed in STM32CubeIDE and pictures of the board

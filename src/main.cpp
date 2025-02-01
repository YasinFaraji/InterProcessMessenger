#include <iostream>

#include "receiver.h"
#include "initiator.h"

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " <initiator|receiver>" << std::endl;
        return EXIT_FAILURE;
    }

    if (std::string(argv[1]) == "initiator")
    {
        IPC::runInitiator();
    }
    else if (std::string(argv[1]) == "receiver")
    {
        IPC::runReceiver();
    }
    else
    {
        std::cerr << "Invalid argument. Use 'initiator' or 'receiver'." << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

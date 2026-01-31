#include <iostream>
#include <iomanip>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsString.h"
#include "clsUtil.h"
#include "clsScreen.h"
#include "clsMainScreen.h"
#include "clsLoginScreen.h"
#include "clsCurrency.h"

using namespace std;

int main()
{
   
    try
    {
        while (true)
        {
            if (!clsLoginScreen::ShowLoginScreen())
            {
                break;
            }
        }
    }
    catch (const exception& ex)
    {
        cout << "\nUnexpected error: " << ex.what() << endl;
    }
    catch (...)
    {
        cout << "\nUnknown fatal error occurred.\n";
    }

    return 0;
}

/*
4. Patient Charges
Write a class named Patient that has member variables for the following data:
- First name, middle name, last name
- Address, city, state, and ZIP code
- Phone number
- Name and phone number of emergency contact
The Patient class should have a constructor that accepts an argument for each member
variable. The Patient class should also have accessor and mutator functions for
each member variable.
Next, write a class named Procedure that represents a medical procedure that has
been performed on a patient. The Procedure class should have member variables for
the following data:
- Name of the procedure
- Date of the procedure
- Name of the practitioner who performed the procedure
- Charges for the procedure
The Procedure class should have a constructor that accepts an argument for each
member variable. The Procedure class should also have accessor and mutator function
for each member variable.
Next, write a program that creates an instance of the Patient class, initialized with
sample data. Then, create three instances of the Procedure class, initialized with the
following data:
----------------------------------------------------------------------------------------------
Procedure #1:                     Procedure #2:                     Procedure #3:
----------------------------------------------------------------------------------------------
Procedure name: Physical Exam     Procedure name: X-ray             Procedure name: Blood test
Date: Today's date                Date: Today's date                Date: Today's date
Practitioner: Dr. Irvine          Practitioner: Dr. Jamison         Practitioner: Dr. Smith
Charge: 250.00                    Charge: 500.00                    Charge: 200.00
----------------------------------------------------------------------------------------------
The program should display the patient's information, information abbout all three of
the procedures, and the total charges of the three procedures.
*/

#include <iostream>
#include <iomanip>

#include "Patient.h"
#include "Procedure.h"

using std::cout;
using std::endl;
using std::fixed;
using std::setprecision;

void Show(const Patient& patient);
void Show(const Procedure& procedure);

int main()
{
	cout << fixed << setprecision(2);

	Patient patient =
	{ 
		"Antero", 
		"Avalos", 
		"Olea",
		"Ferrera Court 67", 
		"Fontana", 
		"CA",
		"92337",
		"1234567890",
		"Kathlees S.", 
		"1234567890" 
	};

	const size_t AMOUNT = 3;
	Procedure procedures[AMOUNT] =
	{
		{ "Physical Exam", "27.09.2020", "Dr. Irvine", 250.00 },
		{ "X-ray", "27.09.2020", "Dr. Jamison", 500.00 },
		{ "Blood text", "27.09.2020", "Dr. Smith", 200.00 }
	};

	cout << "------ Information about patient ------- \n";
	Show(patient);
	cout << "-----------------------------------------\n";

	for (size_t i = 0; i < AMOUNT; i++)
	{
		cout << "\n ---- Information about procedure #" << i + 1 << " ---- \n";
		Show(procedures[i]);
		cout << "-----------------------------------------\n";
	}
	
	double totalCharges = 0;
	for (size_t i = 0; i < AMOUNT; i++)
		totalCharges += procedures[i].GetCharges();

	cout << "\n-----------------------------------------\n";
	cout << "Total charges: $" << totalCharges << endl;
	cout << "-----------------------------------------\n";

	return 0;
}

void Show(const Patient& patient)
{
	cout << "First name: " << patient.GetFirstName() << endl;
	cout << "Middle name: " << patient.GetMiddleName() << endl;
	cout << "Last name: " << patient.GetLastName() << endl;
	cout << "Address: " << patient.GetAddress() << endl;
	cout << "City: " << patient.GetCity() << endl;
	cout << "State: " << patient.GetState() << endl;
	cout << "ZIP: " << patient.GetZIP() << endl;
	cout << "Phone number: " << patient.GetPhoneNumber() << endl;
	cout << "Emergency contact name: " << patient.GetEmergencyContactName() << endl;
	cout << "Emergency contact number: " << patient.GetEmergencyContactNumber() << endl;
}

void Show(const Procedure& procedure)
{
	cout << "Name: " << procedure.GetName() << endl;
	cout << "Date: " << procedure.GetDate() << endl;
	cout << "Pacrioner: " << procedure.GetPractioner() << endl;
	cout << "Charges: $" << procedure.GetCharges() << endl;
}

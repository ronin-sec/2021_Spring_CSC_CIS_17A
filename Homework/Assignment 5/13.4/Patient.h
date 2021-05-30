#include <string>

using std::string;

class Patient
{
private:
	string firstName;
	string middleName;
	string lastName;
	string address;
	string city;
	string state;
	string zip;
	string phoneNumber;
	string emergencyContactName;
	string emergencyContactNumber;

public:
	Patient(
		const string& firstName,
		const string& middleName,
		const string& lastName,
		const string& address,
		const string& city,
		const string& state,
		const string& zip,
		const string& phoneNumber,
		const string& emergencyContactName,
		const string& emergencyContactNumber)
		: firstName(firstName), middleName(middleName), lastName(lastName),
		address(address), city(city), state(state), zip(zip), phoneNumber(phoneNumber),
		emergencyContactName(emergencyContactName), emergencyContactNumber(emergencyContactNumber)
	{ }

	void SetFirstName(const string& firstName) { this->firstName = firstName; }
	void SetMiddleName(const string& middleName) { this->middleName = middleName; }
	void SetLastName(const string& lastName) { this->lastName = lastName; }
	void SetAddress(const string& address) { this->address = address; }
	void SetCity(const string& city) { this->city = city; }
	void SetState(const string& state) { this->state = state; }
	void SetZIP(const string& zip) { this->zip = zip; }
	void SetPhoneNumber(const string& phoneNumber) { this->phoneNumber = phoneNumber; }
	void SetEmergencyContactName(const string& emergencyContactName) { this->emergencyContactName = emergencyContactName; }
	void SetEmergencyContactNumber(const string& emergencyContactNumber) { this->emergencyContactNumber = emergencyContactNumber; }

	string GetFirstName() const { return firstName; }
	string GetMiddleName() const { return middleName; }
	string GetLastName() const { return lastName; }
	string GetAddress() const { return address; }
	string GetCity() const { return city; }
	string GetState() const { return state; }
	string GetZIP() const { return zip; }
	string GetPhoneNumber() const { return phoneNumber; }
	string GetEmergencyContactName() const { return emergencyContactName; }
	string GetEmergencyContactNumber() const { return emergencyContactNumber; }
};

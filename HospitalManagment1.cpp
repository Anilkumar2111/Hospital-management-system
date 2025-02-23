#include <iostream>
#include <vector>
using namespace std;
/*
1. Add Patient
2. Add Doctor
3. Schedule Appointment
4. View Patients
5. View Appointments
6. View Doctors
7. Exit*/
int pid; // patient id
int did; // Doctor id
class Patient
{
public:
    string name;
    string gender;
    int age;
    int id;
    Patient(string n, int a, string g)
    {
        id = pid;
        pid++;
        name = n;
        age = a;
        gender = g;
    }
};
class Doctor
{
public:
    string name;
    string gender;
    int age;
    int id;
    Doctor(string n, int a, string g)
    {
        id = did;
        did++;
        name = n;
        age = a;
        gender = g;
    }
};
class Appointments
{
public:
    int PatientID;
    int doctorID;
    string Date;
    Appointments(int p, int d, string date)
    {
        Date = date;
        PatientID = p;
        doctorID = d;
    }
};
vector<Patient> allPatients;
vector<Doctor> allDoctor;
vector<Appointments> allAppointments;
bool isPatientPresent(int id)
{
    bool ans = false;
    for (int i = 0; i < allPatients.size(); i++)
    {
        if (allPatients[i].id == id)
        {
            ans = true;
        }
    }
    return ans;
}
bool isDoctorPresent(int id)
{
    bool ans = false;
    for (int i = 0; i < allDoctor.size(); i++)
    {
        if (allDoctor[i].id == id)
        {
            ans = true;
        }
    }
    return ans;
}
void addPatient()
{
    string n, g;
    int a;
    cout << "Give the patient name :" << endl;
    cin >> n;
    cout << "Give the patient age :" << endl;
    cin >> a;
    cout << "Give the patient gender :" << endl;
    cin >> g;
    Patient temp(n, a, g);
    allPatients.push_back(temp);
}

void addDoctor()
{
    string n, g;
    int a;
    cout << "Give the Doctor name :" << endl;
    cin >> n;
    cout << "Give the Doctor age :" << endl;
    cin >> a;
    cout << "Give the Doctor gender :" << endl;
    cin >> g;
    Doctor temp(n, a, g);
    allDoctor.push_back(temp);
}

void ScheduleAppointments()
{
    int PatientID;
    int doctorID;
    string Date;

    cout << "Given the Patient ID :" << endl;
    cin >> PatientID;
    cout << "Given the Doctor ID :" << endl;
    cin >> doctorID;
    cout << "Given the DD-MM-YYYY :" << endl;
    cin >> Date;

    if (isPatientPresent(PatientID) == false || isDoctorPresent(doctorID) == false)
    {
        cout << "Invalid Patient ID or Doctor ID" << endl;
        cout << "Appointment Schedule unsuccessful" << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        return;
    }
    Appointments temp(PatientID, doctorID, Date);
    allAppointments.push_back(temp);
}
void viewPatient()
{
    for (int i = 0; i < allPatients.size(); i++)
    {
        cout << "Patients Name: " << allPatients[i].name << endl;
    }

    cout << endl;
    cout << endl;
    cout << endl;
}

void viewDoctor()
{
    for (int i = 0; i < allDoctor.size(); i++)
    {
        cout << "Doctor Name: " << allDoctor[i].name << endl;
    }

    cout << endl;
    cout << endl;
    cout << endl;
}

void viewAppointments()
{
    for (int i = 0; i < allAppointments.size(); i++)
    {
        cout << "Patient ID: " << allAppointments[i].PatientID << " has appointment with Doctor ID: " << allAppointments[i].doctorID << " on DATE: " << allAppointments[i].Date << endl;
    }

    cout << endl;
    cout << endl;
    cout << endl;
}

int main()
{
    pid = 1;
    did = 1;
    int choice;

    do
    {
        cout << "1. Add Patient" << endl;
        cout << "2. Add Doctor" << endl;
        cout << "3. Schedule Appointment" << endl;
        cout << "4. View Patient" << endl;
        cout << "5. View Doctor" << endl;
        cout << "6. View Appointments" << endl;
        cout << "0. Exit" << endl;
        cout << "Give your choice :" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            addPatient();
            break;
        case 2:
            addDoctor();
            break;
        case 3:
            ScheduleAppointments();
            break;
        case 4:
            viewPatient();
            break;
        case 5:
            viewDoctor();
            break;
        case 6:
            viewAppointments();
            break;
        default:
            cout << "Invalid Choice" << endl;
            cout << endl;
            cout << endl;
            cout << endl;
        }

    } while (choice != 0);

    return 0;
}

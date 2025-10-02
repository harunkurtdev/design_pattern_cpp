#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Rooms;

class Thermometer;

class Sensors
{
private:
    string name;

public:
    Sensors(string name)
    {
        this->name = name;
    }
    virtual void Update(Rooms *room) = 0;
    virtual double GetState() = 0;
    string GetName()
    {
        return name;
    }
};

class Rooms
{
protected:
    double temperature;
    double moisture;
    map<Sensors *, string> sensorList;

public:
    virtual void SetTemperature(double temp) = 0;
    virtual double GetTemperature() = 0;
    virtual void SetMoisture(double moist) = 0;
    virtual double GetMoisture() = 0;
    virtual void Attach(Sensors *sensor, string type)
    {
        if (type == "temperature" || type == "moisture")
        {
            sensorList.insert(pair<Sensors *, string>(sensor, type));
        }
        else
        {
            cout << "Wrong type" << endl;
        }
    }

    void Deattach(Sensors *sensor)
    {
        sensorList.erase(sensor);
    }
    void Notify(string type)
    {
        for (auto const &x : sensorList)
        {
            if (x.second == type)
            {
                x.first->Update(this);
                cout << x.first->GetName() << " is notified" << endl;
            }
        }
    }
};

class Room : public Rooms
{
public:
    void SetTemperature(double temp) override
    {
        temperature = temp;
        Notify("temperature");
    }
    double GetTemperature() override
    {
        cout << "Temperature: " << temperature << endl;
        return this->temperature;
    }
    void SetMoisture(double moist) override
    {
        moisture = moist;
        Notify("moisture");
    }
    double GetMoisture() override
    {
        cout << "Moisture: " << moisture << endl;
        return this->moisture;
    }
};

class Thermometer : public Sensors
{
private:
    double temperature;

public:
    Thermometer(string name) : Sensors(name) {}
    void Update(Rooms *room) override
    {
        this->temperature = room->GetTemperature();
    }
    double GetState() override
    {
        return this->temperature;
    }
};

class MoistureMeter : public Sensors
{
private:
    double moisture;

public:
    MoistureMeter(string name) : Sensors(name) {}
    void Update(Rooms *room) override
    {
        this->moisture = room->GetMoisture();
    }
    double GetState() override
    {
        return this->moisture;
    }
};

int main()
{
    Rooms *room1 = new Room();
    Sensors *thermometer1 = new Thermometer("Thermometer 1");
    Sensors *thermometer2 = new Thermometer("Thermometer 2");
    Sensors *moistureMeter1 = new MoistureMeter("Moisture Meter 1");

    room1->Attach(thermometer1, "temperature");
    room1->Attach(thermometer2, "temperature");
    room1->Attach(moistureMeter1, "moisture");

    room1->SetTemperature(25.5);
    cout << thermometer1->GetName() << " state: " << thermometer1->GetState() << endl;
    cout << thermometer2->GetName() << " state: " << thermometer2->GetState() << endl;
    cout << moistureMeter1->GetName() << " state: " << moistureMeter1->GetState() << endl;

    room1->SetMoisture(60.5);
    cout << thermometer1->GetName() << " state: " << thermometer1->GetState() << endl;
    cout << thermometer2->GetName() << " state: " << thermometer2->GetState() << endl;
    cout << moistureMeter1->GetName() << " state: " << moistureMeter1->GetState() << endl;

    room1->Deattach(thermometer2);
    room1->SetTemperature(30.5);
    cout << thermometer1->GetName() << " state: " << thermometer1->GetState() << endl;
    cout << thermometer2->GetName() << " state: " << thermometer2->GetState() << endl;
    cout << moistureMeter1->GetName() << " state: " << moistureMeter1->GetState() << endl;

    delete room1;
    delete thermometer1;
    delete thermometer2;
    delete moistureMeter1;

    return 0;
}
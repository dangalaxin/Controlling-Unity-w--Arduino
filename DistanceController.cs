using UnityEngine;
using System.IO.Ports;

public class DistanceController : MonoBehaviour
{
    SerialPort serialPort = new SerialPort("COM4", 9600);
    public float speed = 2f;
    private int distance = 100;

    void Start()
    {
        if (!serialPort.IsOpen)
        {
            serialPort.Open();
            serialPort.ReadTimeout = 100;
        }
    }

    void Update()
    {
        if (serialPort.IsOpen)
        {
            try
            {
                string data = serialPort.ReadLine();
                distance = int.Parse(data);
            }
            catch { }
        }

        if (distance > 5)
        {
            transform.Translate(Vector3.forward * speed * Time.deltaTime);
        }
        else
        {
            transform.Translate(Vector3.back * speed * Time.deltaTime);
        }
    }

    void OnApplicationQuit()
    {
        if (serialPort.IsOpen)
            serialPort.Close();
    }
}

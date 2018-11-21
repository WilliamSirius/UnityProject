using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Controller : MonoBehaviour {
    public GameObject Player1;
    public static float playerRunningSpeed = 4.0f;
    public static float playerWalkingSpeed = 2.0f;

	// Use this for initialization
	void Start () {
        Player1 = GameObject.Find("Player1");
	}
	
	// Update is called once per frame
	void Update () {
        PlayerControllerKeyboard();
	}

    void PlayerControllerKeyboard()
    {
        if(Input.GetKey(KeyCode.W) && Input.GetKey(KeyCode.LeftShift))
        {
            Player1.transform.Translate(0.0f, 0.0f, Time.deltaTime * playerRunningSpeed);
        }
        if(Input.GetKey(KeyCode.W) && !Input.GetKey(KeyCode.LeftShift))
        {
            Player1.transform.Translate(0.0f, 0.0f, Time.deltaTime * playerWalkingSpeed);
        }
        if (Input.GetKey(KeyCode.S))
        {
            Player1.transform.Translate(0.0f, 0.0f, Time.deltaTime * (-playerWalkingSpeed));
        }
        if (Input.GetKey(KeyCode.A))
        {
            Player1.transform.Translate(Time.deltaTime * (-playerWalkingSpeed), 0.0f, 0.0f);
        }
        if(Input.GetKey(KeyCode.D))
        {
            Player1.transform.Translate(Time.deltaTime * playerWalkingSpeed, 0.0f, 0.0f);
        }
    }

}

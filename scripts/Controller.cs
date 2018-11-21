using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Controller : MonoBehaviour {
    public GameObject Player1;
    public static float playerRunningSpeed = 4.0f;
    public static float playerWalkingSpeed = 2.0f;

	public GameObject firstPersonCam;
	public GameObject thirdPersonCam;
	public GameObject currentCam;
    void Start () {
        Player1 = GameObject.Find("Player1");
		InitCameras();
    }
	
	
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
	
	void InitCameras()
	{
		firstPersonCam = GameObject.Find("FirstPersonCam");
		thirdPersonCam = GameObject.Find("ThirdPersonCam");
		currentCam = thirdPersonCam;
		
		firstPersonCam.GetComponent<Camera>().enabled = false;
		firstPersonCam.GetComponent<AudioListener>().enabled = false;
		
		currentCam.GetComponent<Camera>().enabled = true;
		currentCam.GetComponent<AudioListener>().enabled = true;
	}
	
	void SwitchCamera()
	{
		if(Input.GetKeyDown(KeyCode.F1))
		{
			if(currentCam == firstPersonCam){
				currentCam = thirdPersonCam;
				currentCam.GetComponent<Camera>().enabled = true;
				currentCam.GetComponent<AudioListener>().enabled = true;
				
				firstPersonCam.GetComponent<Camera>().enabled = false;
				firstPersonCam.GetComponent<AudioListener>().enabled = false;
			}
			else{
				currentCam = firstPersonCam;
				currentCam.GetComponent<Camera>().enabled = true;
				currentCam.GetComponent<AudioListener>().enabled = true;
				
				thirdPersonCam.GetComponent<Camera>().enabled = false;
				thirdPersonCam.GetComponent<AudioListener>().enabled = false;
			}
		}
	}

}

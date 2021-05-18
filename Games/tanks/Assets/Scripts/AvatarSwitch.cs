using System.Collections;
using System.Collections.Generic;
using UnityEngine;


public class AvatarSwitch : MonoBehaviour
{
    public Weapon tank_left;
    public Weapon tank_right;

    public GameObject avatar1, avatar2;
    public static int whichAvatarIsOn = 1;


    void Start()
    {

        // anable first avatar and disable another one
        avatar1.GetComponent<Movement>().enabled = true;
        avatar2.GetComponent<Movement>().enabled = false;

        avatar1.GetComponent<Weapon>().enabled = true;
        avatar2.GetComponent<Weapon>().enabled = false;

        CameraFollow.playerTransform = avatar1.transform;
    }

    void Update()
    {


        if (Input.GetButtonUp("Jump")) //if spacebar is released, shoot from correct tank, then switch enabled avatar
        {



            if (whichAvatarIsOn == 1)
            {

                tank_right.Shoot();


            }
            else if (whichAvatarIsOn == 2)
            {
                tank_left.Shoot();


            }


                SwitchAvatar();
            
            


        }


    }
 


    public void SwitchAvatar()
    {
        // processing whichAvatarIsOn variable
        switch (whichAvatarIsOn)
        {

            // if the first avatar is on
            case 1:

                // then the second avatar is on now
                whichAvatarIsOn = 2;

                // disable scipts like movement from the other tank
                avatar1.GetComponent<Movement>().enabled = false;
                avatar2.GetComponent<Movement>().enabled = true;

                avatar1.GetComponent<Weapon>().enabled = false;
                avatar2.GetComponent<Weapon>().enabled = true;


                    CameraFollow.playerTransform = avatar2.transform; //change the camera focus on proper tank
                
                

                break;

            // if the second avatar is on
            case 2:

                // then the first avatar is on now
                whichAvatarIsOn = 1;

                // disable the second one and anable the first one
                avatar1.GetComponent<Movement>().enabled = true;
                avatar2.GetComponent<Movement>().enabled = false;

                avatar1.GetComponent<Weapon>().enabled = true;
                avatar2.GetComponent<Weapon>().enabled = false;

                    CameraFollow.playerTransform = avatar1.transform;
                
                break;

        }
    }
}
using System.Collections;
using System.Collections.Generic;
using UnityEngine;



public class CameraFollow : MonoBehaviour
{

    public static Transform playerTransform;
    private static Transform bullet;
    public float offset;


    void Start()
    {
    playerTransform = GameObject.FindGameObjectWithTag("TLEFT").transform; //start with camera focused on LEFT Tank
    }

    void Update()
    {
        if (AvatarSwitch.whichAvatarIsOn == 1) 
        {
            playerTransform = GameObject.FindGameObjectWithTag("TRIGHT").transform; //change camera focus based on AvatarSwitch's variable
        }
        else if (AvatarSwitch.whichAvatarIsOn == 2)
        {
            playerTransform = GameObject.FindGameObjectWithTag("TLEFT").transform;
        }
        bullet = GameObject.FindGameObjectWithTag("Bullet").transform; //find a bullet in the scene. Finding objects in Update isn't ideal, but couldn't find another way. Also throws NullReferenceException
        if (bullet != null) //if bullet is found, focus camera on it
        {
            playerTransform = bullet;
        }


        }



       void LateUpdate()
    {

        Vector3 temp = transform.position;

        temp.x = playerTransform.position.x;

        temp.x += offset; //camera offset

        transform.position = temp;
    } 
}

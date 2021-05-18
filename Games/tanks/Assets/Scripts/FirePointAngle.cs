using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class FirePointAngle : MonoBehaviour
{
    private Vector3 mouse_pos;
    public Transform target;
    private Vector3 object_pos;
    private float angle;


    void Update() //rotate the FirePoint (from where bullet is shot) to point in crosshair's direction. Works a little bit wonky, but I spent a great deal of time trying to make it work at all
    {
        mouse_pos = Input.mousePosition;
        mouse_pos.z = -20;
        object_pos = Camera.main.WorldToScreenPoint(target.position);
        mouse_pos.x = mouse_pos.x - object_pos.x;
        mouse_pos.y = mouse_pos.y - object_pos.y;
        angle = Mathf.Atan2(mouse_pos.y, mouse_pos.x) * Mathf.Rad2Deg;
        transform.rotation = Quaternion.Euler(0, 0, angle);
    }
}

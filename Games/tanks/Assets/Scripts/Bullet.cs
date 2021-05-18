using System.Collections;
using System.Collections.Generic;
using UnityEngine.UI;
using UnityEngine;

public class Bullet : MonoBehaviour{


    public float speed = 20f;
    public int damage = 10;
    public Rigidbody2D rb;



    void Start() //adding forcec and velocity to bullet's rigid body
    {
        rb.AddForce(Vector3.up * 100000 * Time.deltaTime);
        rb.velocity = transform.right * speed;


    }


    void OnTriggerEnter2D(Collider2D hitInfo) //when the bullet collides with tanks
    {

        tank_right t_right = hitInfo.GetComponent<tank_right>();
        if (t_right != null)
        {
            t_right.GetHit(damage); //invoke GetHit method from tank_right
        }

        tank_left t_left = hitInfo.GetComponent<tank_left>();
        if (t_left != null)
        {
            t_left.GetHit(damage);

        }

        Destroy(gameObject); //destroy the bullet prefab
    }

}

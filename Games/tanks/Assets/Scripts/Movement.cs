using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Movement : MonoBehaviour
{
    public float Speed = 5f; //movement speed

    void Update()
    {
        float h = Input.GetAxisRaw("Horizontal"); //Horizontal left-right

        GetComponent<Rigidbody2D>().velocity = new Vector2(h, 0) * Speed;
    }
}

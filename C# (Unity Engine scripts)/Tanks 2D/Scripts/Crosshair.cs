using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Crosshair : MonoBehaviour
{
    public SpriteRenderer render;

    void Awake()
    {
        Cursor.visible = false; //disable OS cursor
        render.enabled = false;
    }

    void Update()
    {
        if (Input.GetButton("Jump")) //render the crosshair where mouse is when Jump is pressed
        {
            render.enabled = true;
            Vector2 mouseCursorPos = Camera.main.ScreenToWorldPoint(Input.mousePosition);
            transform.position = mouseCursorPos;
        }
        else
        {
            render.enabled = false; //if Jump isn't pressed, don't render the crosshair
        }
    }
}

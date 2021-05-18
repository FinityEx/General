using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Score : MonoBehaviour
{
    public static int healthLeft;
    public static int healthRight;
    public static int scoreAmount_left;
    public static int scoreAmount_right;
    public Text scoreText_left;
    public Text scoreText_right;
    public Text healthTextLeft;
    public Text healthTextRight;

    void Start() //sets up default values for health and score
    {
        scoreAmount_left = 0;
        scoreAmount_right = 0;
        healthLeft = 100;
        healthRight = 100;
    }

    void Update() //displays texts
    {
        scoreText_left.text = "Score: " + scoreAmount_left;
        scoreText_right.text = "Score: " + scoreAmount_right;
        healthTextRight.text = "Health: " + healthRight;
        healthTextLeft.text = "Health: " + healthLeft;

    }
}

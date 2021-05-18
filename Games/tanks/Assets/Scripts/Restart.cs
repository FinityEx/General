using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class Restart : MonoBehaviour
{
    //Script to restart game, attached to the Restart button
    public void RestartGame() 
    {
        SceneManager.LoadScene("SampleScene");
    }
}

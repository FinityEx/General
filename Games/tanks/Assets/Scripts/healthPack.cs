using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class healthPack : MonoBehaviour
{
    public float delay = 20f;
    public GameObject health;

    //Spawns a health pack, restoring addtional 10 points of health to whichever tank grabs it first. Max HP is still 100.


    void Start() 
    {
        InvokeRepeating("Spawn", 5.0f, 20.0f); //spawn healthpack in 5 seconds, then repeat every 20 seconds
  
    }

    void Spawn()
    {
        Instantiate(health, new Vector3(Random.Range(-18, 18), 10, 0), Quaternion.identity); //spawns the pack in random locations in the sky
    }

}

using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Weapon : MonoBehaviour
{

    public Transform firePoint;
    public GameObject bulletPrefab;
    public GameObject dmgPrefab;



    public void Shoot()
    {
       Instantiate(bulletPrefab, firePoint.position, firePoint.rotation); //spawn a bullet

    }




}

using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

//mirror effects and comments, as in tank_left class
public class tank_right : MonoBehaviour
{
    public GameObject floatingPoints;

    public int health = 100;

    public GameObject deathEffect;
    public GameObject restartButton;

    public Text gameOver;
    public Text rightTankWins;
    Vector3 temp = new Vector3(0.5f, 1.0f, 0.0f);

    private void Start()
    {
        gameOver.enabled = false;
        rightTankWins.enabled = false;
        restartButton.SetActive(false);

    }


    public void GetHit(int damage)
    {
        Instantiate(floatingPoints, transform.position + temp, Quaternion.identity);
        health -= damage;
        Score.scoreAmount_left += 1;
        Score.healthRight -= 10;
        if (health <= 0)
        {
            Die();
        }

    }

    public void OnCollisionEnter2D(Collision2D collision)
    {
        if (collision.gameObject.tag == "HEALTH")
        {
            if (health <= 90)
            {
                health += 10;
                Score.healthRight += 10;
            }
            Destroy(collision.gameObject);

        }
    }

    void Die()
    {
        Instantiate(deathEffect, transform.position, Quaternion.identity);
        Destroy(gameObject);
        gameOver.enabled = true;
        rightTankWins.enabled = true;
        Cursor.visible = true;
        restartButton.SetActive(true);
    }


}

using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class tank_left : MonoBehaviour
{
    public GameObject floatingPoints;
    public int health = 100;
    public GameObject deathEffect;
    public GameObject restartButton;
    public Text gameOver;
    public Text leftTankWins;
    Vector3 temp = new Vector3(0.5f, 1.0f, 0.0f);

    private void Start()
    {
        gameOver.enabled = false; //disable the Game Over text
        leftTankWins.enabled = false; //disable Left Tank wins
        restartButton.SetActive(false); //disable Restart Button
    }

    public void GetHit(int damage) //called when tank gets hit
    {
        Instantiate(floatingPoints, transform.position + temp, Quaternion.identity); //displays the -10 pop-up
        health -= damage;
        Score.scoreAmount_right += 1; //updates score to be displayed in Score class
        Score.healthLeft -= 10; //updates health to be displayed in Score class
        if (health <= 0)
        {
            Die(); // :)
        }

    }

    public void OnCollisionEnter2D(Collision2D collision)
    {
        if (collision.gameObject.tag == "HEALTH") //when tank collides with Health Pack
        {
            if (health <= 90) //max HP is 100, so nothing happens if it's higher than 90
            {
                health += 10; //otherwise adds 10 HP
                Score.healthLeft += 10; //update health label in Score class
            }
            Destroy(collision.gameObject); //Destroys health pack
        }


    }

    void Die()
    {
        Instantiate(deathEffect, transform.position, Quaternion.identity); //spawns death animation

        Destroy(gameObject); //destroys tank
        gameOver.enabled = true; //shows Game Over label
        leftTankWins.enabled = true; //if right tank dies, left tank wins
        Cursor.visible = true; //shows OS cursos so player can hit the restart button
        restartButton.SetActive(true); //shows the restart button
    }


}

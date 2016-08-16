<?php

    // configuration
    require("../includes/config.php"); 

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("setting_form.php", ["title" => "Setting"]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // validate submission
        if (empty($_POST["password"]))
        {
            apologize("You must provide your original password.");
        }
        else if (empty($_POST["new_password"]))
        {
            apologize("You must provide your new password.");
        }
        else if (empty($_POST["confirmation"]))
        {
            apologize("You must confirm your new password.");
        }
        else if ($_POST["new_password"] !== $_POST["confirmation"])
        {
            apologize("Passwords do not match!");
        }

        // query database for user
        $rows = CS50::query("SELECT hash FROM users WHERE id = ?", $_SESSION["id"]);

        // if we found user, check password
        if (count($rows) == 1)
        {
            // compare hash of user's input against hash that's in database
            if (password_verify($_POST["password"], $rows[0]["hash"]))
            {
                CS50::query("UPDATE users SET hash = ? WHERE id = ?", password_hash($_POST["new_password"], PASSWORD_DEFAULT), $_SESSION["id"]);

                // redirect to portfolio
                redirect("/");
            }
        }

        // else apologize
        apologize("Database fetch error.");
    }

?>

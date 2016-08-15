<?php

    // configuration
    require("../includes/config.php"); 
    
    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // render portfolio
        render("buy_form.php", ["title" => "Buy"]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // validate submission
        if (empty($_POST["symbol"]))
        {
            apologize("You must specify a stock to buy.");
        }
        else if (empty($_POST["shares"]))
        {
            apologize("You must specify a number of shares.");
        }
        else if (!preg_match("/^\d+$/", $_POST["shares"]))
        {
            apologize("Invalid number of shares.");
        }

        // get the total cost
        $stock = lookup($_POST["symbol"]);
        if ($stock !== false)
        {
            $cost = $stock["price"] * $_POST["shares"];
        }
        else
        {
            apologize("Symbol not found.");
        }
        
        // check user's cash
        $rows = CS50::query("SELECT cash FROM users WHERE id = ?", $_SESSION["id"]);
        if (count($rows) == 1)
        {
            $cash = $rows[0]["cash"];
            if ($cash - $cost < 0)
            {
                apologize("You can't afford that.");
            }

            CS50::query("INSERT INTO portfolios (user_id, symbol, shares) VALUES(?, ?, ?) ON DUPLICATE KEY UPDATE shares = shares + VALUES(shares)", $_SESSION["id"], $_POST["symbol"], $_POST["shares"]);
            CS50::query("UPDATE users SET cash = cash - ? WHERE id = ?", $cost, $_SESSION["id"]);
            
            // redirect to portfolio
            redirect("/");
        }
    }
    
?>

<?php

    // configuration
    require("../includes/config.php"); 
    
    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // get user's portfolio
        $rows = CS50::query("SELECT symbol FROM portfolios WHERE user_id = ?", $_SESSION["id"]);
        
        // define $positions
        $positions = [];
        if (count($rows) !== 0)
        {
            foreach ($rows as $row)
            {
                $positions[] = [
                        "symbol" => $row["symbol"]
                    ];
            }
        }
        
        // render portfolio
        render("sell_form.php", ["positions" => $positions, "title" => "Sell"]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // validate submission
        if (empty($_POST["symbol"]))
        {
            apologize("You must select a stock to sell.");
        }

        // get user's portfoilo
        $rows = CS50::query("SELECT shares FROM portfolios WHERE user_id = ? AND symbol = ?", $_SESSION["id"], $_POST["symbol"]);
        if (count($rows) == 1)
        {
            $share = $rows[0]["share"];
            $stock = lookup($_POST["symbol"]);
            if ($stock !== false)
            {
                $sold_price = $stock["price"] * $share;
            }
            
            CS50::query("UPDATE users SET cash = cash + ? WHERE id = ?", $sold_price, $_SESSION["id"]);
            CS50::query("DELETE FROM portfolios WHERE user_id = ? AND symbol = ?", $_SESSION["id"], $_POST["symbol"]);
            
            // redirect to portfolio
            redirect("/");
        }
        apologize("Incorrect stock.");
    }
    
?>

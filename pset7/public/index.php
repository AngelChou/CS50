<?php

    // configuration
    require("../includes/config.php"); 
    
    // get user's portfolio
    $rows = CS50::query("SELECT symbol, shares FROM portfolios WHERE user_id = ?", $_SESSION["id"]);
    
    // define $positions
    $positions = [];
    if (count($rows) !== 0)
    {
        foreach ($rows as $row)
        {
            $stock = lookup($row["symbol"]);
            if ($stock !== false)
            {
                $positions[] = [
                    "name" => $stock["name"],
                    "price" => $stock["price"],
                    "shares" => $row["shares"],
                    "symbol" => $row["symbol"]
                ];
            }
        }
    }
    
    // get user's cash
    $rows = CS50::query("SELECT cash FROM users WHERE id = ?", $_SESSION["id"]);
    
    if (count($rows) == 1)
    {
        $cash = $rows[0]["cash"];
    }
    else
    {
        $cash = 0;
    }
    $cash = number_format($cash, 2, ".", ",");

    // render portfolio
    render("portfolio.php", ["positions" => $positions, "cash" => $cash, "title" => "Portfolio"]);

?>

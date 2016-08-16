<?php

    // configuration
    require("../includes/config.php"); 
    
    // get user's portfolio
    $rows = CS50::query("SELECT * FROM history WHERE user_id = ?", $_SESSION["id"]);
    
    // define $positions
    $positions = [];
    if (count($rows) !== 0)
    {
        foreach ($rows as $row)
        {
            $positions[] = [
                "transaction" => $row["transaction"],
                "time" => $row["time"],
                "symbol" => $row["symbol"],
                "shares" => $row["shares"],
                "price" => number_format($row["price"], 2, ".", ",")
            ];
        }
    }
    
    // render history
    render("history_show.php", ["positions" => $positions, "title" => "History"]);

?>

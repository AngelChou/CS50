<?php

    // configuration
    require("../includes/config.php");

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("quote_form.php", ["title" => "Quote"]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // validate submission
        if (empty($_POST["symbol"]))
        {
            apologize("You must provide a symbol.");
        }
        
        // look up a stock's latest price
        $stock = lookup($_POST["symbol"]);
        
        if ($stock === false)
        {
            apologize("Symbol not found.");
        }
        else 
        {
            $price = number_format($stock["price"], 2, ".", ",");
            render("quote_show.php", ["name" => $stock["name"], "symbol" => $stock["symbol"], "price" => $price]);
        } 
    }

?>
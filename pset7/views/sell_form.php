<form action="sell.php" method="post">
    <select name="symbol" class = "form-control">
        <option>Symbol</option>
        <?php foreach ($positions as $position): ?>
            <option value=<?= $position["symbol"] ?>><?= $position["symbol"] ?></option>
        <?php endforeach ?>
    </select>
    <br><br>
    <button type="submit" class="btn btn-default">Sell</button>
</form>
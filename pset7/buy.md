# C$50 Finance / buy

## buy
- display form
  - get stock, number of shares
- add stock to portfolio
- update cash

## display form
- HTML form
- ask for **symbol** and number of **shares**

## add stock to portfolio
- can the user afford the stock?
```SELECT cash FROM users WHERE id = 7```
- buying more of the same stock
```INSERT INTO portfolios (user_id, symbol, shares) VALUES(7, 'DVN.V', 10) ON DUPLICATE KEY UPDATE shares = shares + VALUES(shares)```

## update cash
- a user's cash is stored in the **users** table
```UPDATE users SET cash = cash - 9999 WHERE id = 7```

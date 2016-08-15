# C$50 Finance / sell

## sell
- display form
  - get stock to sell
- remove stock from portfolio
- update cash

## display form
- display the user's stocks
```SELECT * FROM portfolios WHERE user_id = 7```

## remove stock from portfolio
```DELETE FROM portfolios WHERE user_id = 7 AND symbol = "AAPL"```

## update cash
- stock is sold at its current price
  - lookup

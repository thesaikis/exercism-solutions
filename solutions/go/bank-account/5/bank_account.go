package account

import "sync"

type Account struct {
	balance int64
	closed  bool
	lock    sync.Mutex
}

// Open returns a new Account with the given amount as the balance.
func Open(amount int64) *Account {
	if amount < 0 {
		return nil
	}

	return &Account{
		balance: amount,
	}
}

// Balance returns the balance of the account.
func (a *Account) Balance() (int64, bool) {
	a.lock.Lock()
	defer a.lock.Unlock()

	if a.closed {
		return 0, false
	}

	return a.balance, true
}

// Deposit deposits the given amount into the account, or withdraws, if able.
func (a *Account) Deposit(amount int64) (int64, bool) {
	a.lock.Lock()
	defer a.lock.Unlock()

	if a.closed || (amount < 0 && a.balance < -amount) {
		return 0, false
	}

	a.balance += amount
	return a.balance, true
}

// Close closes the account.
func (a *Account) Close() (int64, bool) {
	a.lock.Lock()
	defer a.lock.Unlock()

	if a.closed {
		return 0, false
	}

	a.closed = true
	oldBalance := a.balance
	a.balance = 0
	return oldBalance, true
}

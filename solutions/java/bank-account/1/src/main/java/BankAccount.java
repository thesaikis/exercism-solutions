class BankAccount {
    private int balance;
    private boolean isClosed = true;

    void open() throws BankAccountActionInvalidException {
        if (!isClosed)
            throw new BankAccountActionInvalidException("Account already open");
        this.isClosed = false;
    }

    synchronized void close() throws BankAccountActionInvalidException {
        if (isClosed)
            throw new BankAccountActionInvalidException("Account not open");
        isClosed = true;
        balance = 0;
    }

    synchronized int getBalance() throws BankAccountActionInvalidException {
        checkValid(0);
        return balance;
    }

    synchronized void deposit(int amount) throws BankAccountActionInvalidException {
        checkValid(amount);
        balance += amount;
    }

    synchronized void withdraw(int amount) throws BankAccountActionInvalidException {
        checkValid(amount);
        if (amount > balance)
            throw new BankAccountActionInvalidException("Cannot withdraw more money than is currently in the account");
        balance -= amount;
    }

    private void checkValid(int amount) throws BankAccountActionInvalidException {
        if (isClosed)
            throw new BankAccountActionInvalidException("Account closed");
        if (amount < 0)
            throw new BankAccountActionInvalidException("Cannot deposit or withdraw negative amount");
    }
}
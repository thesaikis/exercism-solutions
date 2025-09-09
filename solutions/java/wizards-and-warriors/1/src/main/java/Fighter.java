abstract class Fighter {

    boolean isVulnerable() {
        return false;
    }

    public String toString() {
        return String.format("Fighter is a %s", this.getClass().getSimpleName());
    }

    abstract int damagePoints(Fighter fighter);
}

class Warrior extends Fighter {

    @Override
    int damagePoints(Fighter fighter) {
        return fighter.isVulnerable() ? 10 : 6;
    }
}

class Wizard extends Fighter {
    private boolean isPrepared = false;

    @Override
    boolean isVulnerable() {
        return !isPrepared;
    }

    @Override
    int damagePoints(Fighter fighter) {
        return isPrepared ? 12 : 3;
    }

    void prepareSpell() {
        isPrepared = true;
    }
}

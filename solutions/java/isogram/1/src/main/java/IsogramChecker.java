class IsogramChecker {

    boolean isIsogram(String phrase) {
        String modifiedPhrase = phrase.toLowerCase().replaceAll("[^\\p{Alpha}]", "");
        return modifiedPhrase.length() == modifiedPhrase.chars().distinct().count();
    }

}

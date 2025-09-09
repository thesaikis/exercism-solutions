class Badge {
    public String print(Integer id, String name, String department) {
        department = department != null ? department.toUpperCase() : "OWNER";

        if (id != null) {
            return String.format("[%d] - %s - %s", id, name, department);
        } else {
            return String.format("%s - %s", name, department);
        }
    }
}

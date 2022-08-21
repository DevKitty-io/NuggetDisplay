void setup() {
    Serial.begin(115200);
}

void loop() {
    String values[] = {"First","Second","Third","Fourth","Fifth"};
    getValues(*values);
}

void getValues(String* valArray) {
    Serial.println();
}
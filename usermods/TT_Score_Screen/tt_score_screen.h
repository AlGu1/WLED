#pragma once

#include "wled.h"

//This is an empty v2 usermod template. Please see the file usermod_v2_example.h in the EXAMPLE_v2 usermod folder for documentation on the functions you can use!

class UsermodTTScoreScreen : public Usermod {
  private:
    int button1 = 12;
    bool button1PressedBefore _INIT(false);
    int button2 = 5;
    bool button2PressedBefore _INIT(false);
    int button3 = 13;
    bool button3PressedBefore _INIT(false);
    int button4 = 14;
    bool button4PressedBefore _INIT(false);
    int homeCount = 0;
    int guestCount = 0;
   
  public:
    void setup() {
      pinMode(button1, INPUT_PULLUP);
      pinMode(button2, INPUT_PULLUP);
      pinMode(button3, INPUT_PULLUP);
      pinMode(button4, INPUT_PULLUP);

      initSegments();
    }

    void initSegments(){
      strip.setSegment(0, 0, 28, 2);
      strip.getSegment(0).colors[0] = WHITE;
      strip.getSegment(0).setOption(0, false);
      showHomeCount();
      showGuestCount();
    }

    void loop() {
      handleButton(button1, button1PressedBefore);
      handleButton(button2, button2PressedBefore);
      handleButton(button3, button3PressedBefore);
      handleButton(button4, button4PressedBefore);
    }

    bool isButtonPressed(int btnPinNr)
    {
      return digitalRead(btnPinNr) == HIGH;
    }

    void handleButton(int btnPinNr, bool &btnPressedBefore)
    {
      if (isButtonPressed(btnPinNr)) //pressed
      {
        btnPressedBefore = true;
      }
      else if (!isButtonPressed(btnPinNr) && btnPressedBefore) //released
      {
        btnShortPressAction(btnPinNr);
        btnPressedBefore = false;
      }
    }

    void btnShortPressAction(int btnPinNr)
    {
      if(btnPinNr == button1){
        homePlusButton();
      }
      if(btnPinNr == button2){
        homeMinusButton();
      }
      if(btnPinNr == button3){
        guestMinusButton();
      }
      if(btnPinNr == button4){
        guestPlusButton();
      }
    }
    void homePlusButton(){
      if(homeCount < 9){
        homeCount++;
      }
      showHomeCount();
    }
    void homeMinusButton(){
      if(homeCount > 0){
        homeCount--;
      }
      showHomeCount();
    }
    void guestPlusButton(){
      if(guestCount < 9){
        guestCount++;
      }
      showGuestCount();
    }
    void guestMinusButton(){
      if(guestCount > 0){
        guestCount--;
      }
      showGuestCount();
    }

    void showHomeCount() {
      for (int i = 0; i < 4; i++) {
        strip.setSegment(i, 0, 0, 2);
        strip.getSegment(i).setOption(0, false);
        strip.getSegment(i).colors[0] = WHITE;
      }

      switch (homeCount)
      {
      case 0:
        strip.setSegment(0, 0, 12, 2);
        strip.getSegment(0).setOption(0, true);
        strip.setSegment(1, 0, 0, 2);
        strip.getSegment(1).setOption(0, false);
        strip.setSegment(2, 0, 0, 2);
        strip.getSegment(2).setOption(0, false);
        break;
      case 1:
        strip.setSegment(0, 4, 8, 2);
        strip.getSegment(0).setOption(0, true);
        strip.setSegment(1, 0, 0, 2);
        strip.getSegment(1).setOption(0, false);
        strip.setSegment(2, 0, 0, 2);
        strip.getSegment(2).setOption(0, false);
        break;
      case 2:
        strip.setSegment(0, 0, 4, 2);
        strip.getSegment(0).setOption(0, true);
        strip.setSegment(1, 6, 10, 2);
        strip.getSegment(1).setOption(0, true);
        strip.setSegment(2, 12, 14, 2);
        strip.getSegment(2).setOption(0, true);
        break;
      case 3:
        strip.setSegment(0, 2, 10, 2);
        strip.getSegment(0).setOption(0, true);
        strip.setSegment(1, 12, 14, 2);
        strip.getSegment(1).setOption(0, true);
        strip.setSegment(2, 0, 0, 2);
        strip.getSegment(2).setOption(0, false);
        break;    
      case 4:
        strip.setSegment(0, 4, 8, 2);
        strip.getSegment(0).setOption(0, true);
        strip.setSegment(1, 10, 14, 2);
        strip.getSegment(1).setOption(0, true);
        strip.setSegment(2, 0, 0, 2);
        strip.getSegment(2).setOption(0, false);
        break;       
      case 5:
        strip.setSegment(0, 2, 6, 2);
        strip.getSegment(0).setOption(0, true);
        strip.setSegment(1, 8, 14, 2);
        strip.getSegment(1).setOption(0, true);
        strip.setSegment(2, 0, 0, 2);
        strip.getSegment(2).setOption(0, false);
        break;       
      case 6:
        strip.setSegment(0, 0, 6, 2);
        strip.getSegment(0).setOption(0, true);
        strip.setSegment(1, 10, 14, 2);
        strip.getSegment(1).setOption(0, true);
        break;       
      case 7:
        strip.setSegment(0, 4, 10, 2);
        strip.getSegment(0).setOption(0, true);
        strip.setSegment(1, 0, 0, 2);
        strip.getSegment(1).setOption(0, false);
        strip.setSegment(2, 0, 0, 2);
        strip.getSegment(2).setOption(0, false);
        break;       
      case 8:
        strip.setSegment(0, 0, 14, 2);
        strip.getSegment(0).setOption(0, true);
        strip.setSegment(1, 0, 0, 2);
        strip.getSegment(1).setOption(0, false);
        strip.setSegment(2, 0, 0, 2);
        strip.getSegment(2).setOption(0, false);
        break;       
      case 9:
        strip.setSegment(0, 2, 14, 2);
        strip.getSegment(0).setOption(0, true);
        strip.setSegment(1, 0, 0, 2);
        strip.getSegment(1).setOption(0, false);
        strip.setSegment(2, 0, 0, 2);
        strip.getSegment(2).setOption(0, false);
        break;
      }
    }
    void showGuestCount() {
      for (int i = 5; i < 10; i++) {
        strip.setSegment(i, 0, 0, 2);
        strip.getSegment(i).setOption(0, false);
        strip.getSegment(i).colors[0] = WHITE;
      }

      switch (guestCount)
      {
      case 0:
        strip.setSegment(5, 16, 28, 2);
        strip.getSegment(5).setOption(0, true);
        strip.setSegment(6, 0, 0, 2);
        strip.getSegment(6).setOption(0, false);
        strip.setSegment(7, 0, 0, 2);
        strip.getSegment(7).setOption(0, false);
        break;
      case 1:
        strip.setSegment(5, 16, 18, 2);
        strip.getSegment(5).setOption(0, true);
        strip.setSegment(6, 26, 28, 2);
        strip.getSegment(6).setOption(0, true);
        strip.setSegment(7, 0, 0, 2);
        strip.getSegment(7).setOption(0, false);
        break;
      case 2:
        strip.setSegment(5, 14, 16, 2);
        strip.getSegment(5).setOption(0, true);
        strip.setSegment(6, 18, 22, 2);
        strip.getSegment(6).setOption(0, true);
        strip.setSegment(7, 24, 28, 2);
        strip.getSegment(7).setOption(0, true);
        break;
      case 3:
        strip.setSegment(5, 14, 20, 2);
        strip.getSegment(5).setOption(0, true);
        strip.setSegment(6, 24, 28, 2);
        strip.getSegment(6).setOption(0, true);
        strip.setSegment(7, 0, 0, 2);
        strip.getSegment(7).setOption(0, false);
        break;       
      case 4:
        strip.setSegment(5, 14, 18, 2);
        strip.getSegment(5).setOption(0, true);
        strip.setSegment(6, 22, 24, 2);
        strip.getSegment(6).setOption(0, true);
        strip.setSegment(7, 26, 28, 2);
        strip.getSegment(7).setOption(0, true);
        break;       
      case 5:
        strip.setSegment(5, 14, 20, 2);
        strip.getSegment(5).setOption(0, true);
        strip.setSegment(6, 22, 26, 2);
        strip.getSegment(6).setOption(0, true);
        strip.setSegment(7, 0, 0, 2);
        strip.getSegment(7).setOption(0, false);
        break;       
      case 6:
        strip.setSegment(5, 14, 24, 2);
        strip.getSegment(5).setOption(0, true);
        strip.setSegment(6, 0, 0, 2);
        strip.getSegment(6).setOption(0, false);
        strip.setSegment(7, 0, 0, 2);
        strip.getSegment(7).setOption(0, false);
        break;       
      case 7:
        strip.setSegment(5, 16, 18, 2);
        strip.getSegment(5).setOption(0, true);
        strip.setSegment(6, 24, 28, 2);
        strip.getSegment(6).setOption(0, true);
        strip.setSegment(7, 0, 0, 2);
        strip.getSegment(7).setOption(0, false);
        break;       
      case 8:
        strip.setSegment(5, 14, 28, 2);
        strip.getSegment(5).setOption(0, true);
        strip.setSegment(6, 0, 0, 2);
        strip.getSegment(6).setOption(0, false);
        strip.setSegment(7, 0, 0, 2);
        strip.getSegment(7).setOption(0, false);
        break;       
      case 9:
        strip.setSegment(5, 14, 20, 2);
        strip.getSegment(5).setOption(0, true);
        strip.setSegment(6, 22, 28, 2);
        strip.getSegment(6).setOption(0, true);
        strip.setSegment(7, 0, 0, 2);
        strip.getSegment(7).setOption(0, false);
        break;
      }
    }

    /*
     * addToJsonState() can be used to add custom entries to the /json/state part of the JSON API (state object).
     * Values in the state object may be modified by connected clients
     */
    void addToJsonState(JsonObject& root)
    {
      root["HomeCount"] = homeCount;
      root["GuestCount"] = guestCount;
    }
    /*
     * readFromJsonState() can be used to receive data clients send to the /json/state part of the JSON API (state object).
     * Values in the state object may be modified by connected clients
     */
    void readFromJsonState(JsonObject& root)
    {
      userVar0 = root["HomeCount"] | homeCount;
      if (userVar0 <= 9 && userVar0 >= 0) {
        homeCount = userVar0;
        showHomeCount();
      }
      userVar1 = root["GuestCount"] | guestCount;
      if (userVar1 <= 9 && userVar1 >= 0) {
        guestCount = userVar1;
        showGuestCount();
      }
    }
    
   /**
   * addToJsonInfo() can be used to add custom entries to the /json/info part of the JSON API.
   * Creating an "u" object allows you to add custom key/value pairs to the Info section of the WLED web UI.
   * Below it is shown how this could be used for e.g. a light sensor
   */
    void addToJsonInfo(JsonObject &root)
    {
      //this code adds "u":{"&#x26A1; Ping fix pings": m_pingCount} to the info object
      JsonObject user = root["u"];
      if (user.isNull())
        user = root.createNestedObject("u");

      String uiDomString = "&#127955;Ergebnis Anzeige:<span style=\"display:block;padding-left:25px;\">Heim:<input type=\"number\" min=\"0\" max=\"9\" value=\"";
      uiDomString += homeCount;
      uiDomString += "\" onchange=\"requestJson({HomeCount:parseInt(this.value)});\"></span>";
      JsonArray infoArr = user.createNestedArray(uiDomString);
      
      String uiDomString2 = "&nbsp;<span style=\"display:block;padding-left:25px;\">Gast:<input type=\"number\" min=\"0\" max=\"9\" value=\"";
      uiDomString2 += guestCount;
      uiDomString2 += "\" onchange=\"requestJson({GuestCount:parseInt(this.value)});\"></span>";
      infoArr.add(uiDomString2);
    }
    /*
     * addToConfig() can be used to add custom persistent settings to the cfg.json file in the "um" (usermod) object.
     * It will be called by WLED when settings are actually saved (for example, LED settings are saved)
     * If you want to force saving the current state, use serializeConfig() in your loop().
     * 
     * CAUTION: serializeConfig() will initiate a filesystem write operation.
     * It might cause the LEDs to stutter and will cause flash wear if called too often.
     * Use it sparingly and always in the loop, never in network callbacks!
     * 
     * addToConfig() will also not yet add your setting to one of the settings pages automatically.
     * To make that work you still have to add the setting to the HTML, xml.cpp and set.cpp manually.
     * 
     * I highly recommend checking out the basics of ArduinoJson serialization and deserialization in order to use custom settings!
     */
    /*
    void addToConfig(JsonObject& root)
    {
      //JsonObject top = root.createNestedObject("exampleUsermod");
      //top["great"] = userVar0; //save this var persistently whenever settings are saved
    }
    */
    /*
     * readFromConfig() can be used to read back the custom settings you added with addToConfig().
     * This is called by WLED when settings are loaded (currently this only happens once immediately after boot)
     * 
     * readFromConfig() is called BEFORE setup(). This means you can use your persistent values in setup() (e.g. pin assignments, buffer sizes),
     * but also that if you want to write persistent values to a dynamic buffer, you'd need to allocate it here instead of in setup.
     * If you don't know what that is, don't fret. It most likely doesn't affect your use case :)
     */
    /*
    void readFromConfig(JsonObject& root)
    {
      //JsonObject top = root["top"];
      //userVar0 = top["great"] | 42; //The value right of the pipe "|" is the default value in case your setting was not present in cfg.json (e.g. first boot)
    }
    */
    /*
     * getId() allows you to optionally give your V2 usermod an unique ID (please define it in const.h!).
     * This could be used in the future for the system to determine whether your usermod is installed.
     */
    uint16_t getId()
    {
      return USERMOD_ID_TTSCORESCREEN;
    }
};
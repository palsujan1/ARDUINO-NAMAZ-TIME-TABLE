#!/usr/bin/env python3
"""
Simple PIC16F676 HEX File Uploader
Python-based GUI uploader (Cross-platform)
Requires: tkinter, pk2cmd or pickit software
"""

import tkinter as tk
from tkinter import filedialog, messagebox
import subprocess
import os
import platform

class PICUploader:
    def __init__(self, root):
        self.root = root
        self.root.title("PIC16F676 Simple Uploader")
        self.root.geometry("500x300")

        # Title
        title = tk.Label(root, text="PIC16F676 HEX Uploader",
                        font=("Arial", 16, "bold"))
        title.pack(pady=10)

        # HEX file selection
        self.file_label = tk.Label(root, text="No file selected",
                                   fg="gray")
        self.file_label.pack(pady=5)

        browse_btn = tk.Button(root, text="Browse HEX File",
                              command=self.browse_file,
                              width=20, height=2)
        browse_btn.pack(pady=10)

        # Upload button
        self.upload_btn = tk.Button(root, text="Upload to PIC16F676",
                                    command=self.upload_hex,
                                    width=20, height=2,
                                    bg="green", fg="white",
                                    state=tk.DISABLED)
        self.upload_btn.pack(pady=10)

        # Status
        self.status = tk.Label(root, text="Ready", fg="blue")
        self.status.pack(pady=10)

        # Instructions
        instructions = tk.Label(root,
                               text="1. Connect PICkit to PIC16F676\n"
                                    "2. Select HEX file\n"
                                    "3. Click Upload",
                               justify=tk.LEFT)
        instructions.pack(pady=10)

        self.hex_file = None

    def browse_file(self):
        """Browse and select HEX file"""
        filename = filedialog.askopenfilename(
            title="Select HEX File",
            filetypes=(("HEX files", "*.hex"), ("All files", "*.*"))
        )

        if filename:
            self.hex_file = filename
            self.file_label.config(text=os.path.basename(filename),
                                  fg="black")
            self.upload_btn.config(state=tk.NORMAL)
            self.status.config(text="File selected - Ready to upload",
                             fg="blue")

    def upload_hex(self):
        """Upload HEX file to PIC"""
        if not self.hex_file:
            messagebox.showerror("Error", "Please select a HEX file first!")
            return

        self.status.config(text="Uploading...", fg="orange")
        self.root.update()

        try:
            # Try pk2cmd first (command line tool)
            if self.check_pk2cmd():
                cmd = ["pk2cmd", "-P", "PIC16F676",
                      "-F", self.hex_file, "-M", "-R"]
                result = subprocess.run(cmd, capture_output=True, text=True)

                if result.returncode == 0:
                    self.status.config(text="SUCCESS! LED should blink now!",
                                     fg="green")
                    messagebox.showinfo("Success",
                                       "Upload complete!\n"
                                       "Your PIC16F676 is now running.")
                else:
                    raise Exception(result.stderr)
            else:
                # Show manual instructions
                messagebox.showinfo("Manual Upload",
                    f"pk2cmd not found.\n\n"
                    f"Please manually upload using PICkit software:\n"
                    f"1. Open PICkit Programmer\n"
                    f"2. Select Device: PIC16F676\n"
                    f"3. Import Hex: {self.hex_file}\n"
                    f"4. Click Write")
                self.status.config(text="Please upload manually",
                                 fg="orange")

        except Exception as e:
            self.status.config(text="Upload failed!", fg="red")
            messagebox.showerror("Upload Error",
                               f"Failed to upload:\n{str(e)}\n\n"
                               f"Check connections and try again.")

    def check_pk2cmd(self):
        """Check if pk2cmd is installed"""
        try:
            result = subprocess.run(["pk2cmd", "-?"],
                                  capture_output=True, text=True)
            return True
        except FileNotFoundError:
            return False

if __name__ == "__main__":
    root = tk.Tk()
    app = PICUploader(root)
    root.mainloop()

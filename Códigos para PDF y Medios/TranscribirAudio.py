import tkinter as tk
from tkinter import filedialog
import speech_recognition as sr
import os

# Transcribir audio a texto
def transcribe_audio(audio_file):
    recognizer = sr.Recognizer()

    # Leer el archivo de audio
    with sr.AudioFile(audio_file) as source:
        audio = recognizer.record(source)
    
    # Usar Google Web Speech API para la transcripción
    try:
        text = recognizer.recognize_google(audio)
        return text
    except sr.UnknownValueError:
        return "No se pudo entender el audio"
    except sr.RequestError as e:
        return f"No se pudo conectar con el servicio de Google; {e}"

# Guardar la transcripción en un archivo de texto
def save_transcription(text, filename="transcription.txt"):
    with open(filename, "w") as file:
        file.write(text)
    print(f"Transcripción guardada en {filename}")

# Selector de archivo para escoger el archivo de audio
def select_audio_file():
    root = tk.Tk()
    root.withdraw()  # Oculta la ventana principal de tkinter
    file_path = filedialog.askopenfilename(
        title="Selecciona el archivo de audio",
        filetypes=[("Archivos de audio", "*.wav")]
    )
    return file_path

# Usar el selector de archivo para seleccionar el archivo de audio
audio_file = select_audio_file()

# Verificar si se seleccionó un archivo
if audio_file:
    # Llamar a la función para transcribir
    transcription = transcribe_audio(audio_file)

    # Mostrar la transcripción en pantalla
    print("Texto transcrito:", transcription)

    # Guardar la transcripción en un archivo .txt
    save_transcription(transcription)
else:
    print("No se seleccionó ningún archivo.")

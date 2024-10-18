from moviepy.video.io.VideoFileClip import VideoFileClip

# Cargar el video
video = VideoFileClip(r"D:\La era de hielo.mp4")

# Definir los tiempos de inicio y fin en segundos
inicio = 20  # 20 segundos
fin = 4620   # 1 hora y 17 minutos (4620 segundos)

# Recortar el video
video_recortado = video.subclip(inicio, fin)

# Guardar el video recortado
video_recortado.write_videofile(r"D:\video_recortado.mp4", codec="libx264")


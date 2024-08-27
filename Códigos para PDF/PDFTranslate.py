import PyPDF2
from deep_translator import GoogleTranslator

def extract_text_from_pdf(pdf_path, exclude_pages=None):
    if exclude_pages is None:
        exclude_pages = []
        
    pdf_text = ""
    with open(pdf_path, "rb") as file:
        reader = PyPDF2.PdfReader(file)
        num_pages = len(reader.pages)
        
        for i in range(num_pages):
            if i not in exclude_pages:
                page = reader.pages[i]
                text = page.extract_text()
                if text:  # Ignora las páginas vacías
                    pdf_text += text
    return pdf_text

def split_text(text, max_length=5000):
    """Divide el texto en fragmentos de tamaño máximo especificado."""
    fragments = []
    while len(text) > max_length:
        # Encuentra el último espacio en el límite del tamaño máximo
        split_point = text.rfind(' ', 0, max_length)
        if split_point == -1:  # Si no se encuentra un espacio, usa el límite
            split_point = max_length
        fragments.append(text[:split_point])
        text = text[split_point:].strip()
    if text:
        fragments.append(text)
    return fragments

def translate_text(text, dest_language='es'):
    translator = GoogleTranslator(source='auto', target=dest_language)
    translated_parts = []
    parts = split_text(text)
    for part in parts:
        translated_text = translator.translate(part)
        translated_parts.append(translated_text)
    return ''.join(translated_parts)

def save_translated_text(translated_text, output_file):
    with open(output_file, "w", encoding="utf-8") as file:
        file.write(translated_text)

if __name__ == "__main__":
    pdf_path = r"C:\Users\JUAN PABLO\Desktop\Lecture 01 - The end of Moore´s law.pdf"  # Ruta del archivo PDF
    output_file = r"C:\Users\JUAN PABLO\Desktop\archivo_traducido.txt"  #  Ruta del archivo de salida

    # Especifica las páginas que deseas excluir (índices basados en 0)
    exclude_pages = [10] 

    # Extraer el texto del PDF
    pdf_text = extract_text_from_pdf(pdf_path, exclude_pages=exclude_pages)
    
    # Traducir el texto al español
    translated_text = translate_text(pdf_text, dest_language='es')
    
    # Guardar el texto traducido en un archivo
    save_translated_text(translated_text, output_file)
    
    print("La traducción ha sido guardada en", output_file)

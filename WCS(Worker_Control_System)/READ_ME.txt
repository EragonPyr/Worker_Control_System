----------------------------------------Worker Control System----------------------------------------
WCS temel olarak 4 yerde veri tutar.

admin.txt:

Bu dosyada sistemin admin bilgileri(adminid,adminpassword) tutulur.
Eğer adminin id'si ve/veya şifresi değiştirilmek istenirse bu dosya üzerinden
veya admin paneli üzerinden değiştirilebilir(Admin paneli üzerinden değiştirmek tavsiye edilir)

happen.txt:

Bu dosyada çalışma saatlerinin başlangıç ve bitiş saatleri saat dakika biçiminde tutulur.
Eğer çalışma saatleri değiştirilmek istenirse dosya üzerinden veya admin paneli üzerinden
değiştirilebilir(Admin paneli üzerinden değiştirmek tavsiye edilir)

messages.txt:

Bu dosyada userlar tarafından admin e gönderilen mesajlar tutulur.Eski mesajlar incelenmek istenirse
dosya üzerinden yapılabilir.

workers.txt:

Bu dosyada bu çalışma alınındaki çalışanların tüm bilgileri tutulur.Eğer buradaki veriler değiştirilmek
yada ekleme yapmak istenirse dosya üzerinden yapılınılmalıdır yanlızca kullanıcı şifreleri
kullanıcı paneli üzerinden değiştirilebilir.



Bunun dışında workers.txt dosyası sadece admin paneli üzerinden sistem kapatıldığında güncellenir.Diğer 
dosyalar ise eylem tamamlanır tamamlanmaz güncellenmektedir.
Ayrıca sistem kuralları sebebiyle çalışan id leri 4 basamaklı ve 1<=ilk basamak şartlarını admin id si
ise 5 basamak ve 1<=ilk basamak şartlarını sağlamalıdır yoksa sistem hata verecektir ve uyarı verdikten
sonra kendini kapatacaktır.
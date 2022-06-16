### data-structures

Kodlamaya “Sayılar” adında bir txt dosyası oluşturmakla başlanılmıştır. Ardından 
“Sayilar.txt” dosyasına rastgele sayılar girilmiştir. Daha sonrasında 
dosyadan sayılar çekilmeye başlanmıştır. Bu işlemler GeeksforGeeks web sayfasından 
yararlanılarak yapılmıştır. Dosyadan okuma ve yazma yapılmıştır. Okuma ve yazma 
işlemlerinin yapılabilmesi için dosya açma işlemine ilave olarak açılan dosyayı gösteren bir
göstericiye (pointer) ihtiyaç duyulmaktadır. Bu gösterici fopen fonksiyonu tarafından 
döndürülmektedir.

Dosya içeriğini tutması için char tipinde bir pointer oluşturulmuştur. Bellekte malloc ile 
yer açılmış ardından fgets komutu ile p pointerına “Sayilar.txt” dosyasındaki veriler atılmıştır. Bu atama işlemi txt dosyasının içeriği kaç byte ise ona göre yapılmıştır. “Sayilar.txt” dosyasının içeriğinin kaç byte olduğu ftell() fonksiyonu ile ayrı bir fonksiyonda hesaplanmıştır. Ftell() fonksiyonu stream parametresi ile gösterilen akışın aktif dosya konumunu geri döndürür. Akış ikili modda açıldığında, bu fonksiyon tarafından elde edilen değer dosyanın başından itibaren bayt değeridir. Böylece dinamik bir şekilde “Sayilar.txt” dosyasındaki elemanlar bellekte tutulmuştur.
Char tipinde bir dizi ile tutulan sayıları integer bir diziye atamak için bir elemanlık geçiçi 
bir dizi oluşturulmuştur. Bu dizinin bir elemanlı olmasının sebebi atoi() fonksiyonunun str 
parametresi ile gösterilen karakter dizisini int bir değere çevirmesidir. Int tipine çevrilen sayı daha sonrasında integer tipindeki bir diziye atanmıştır. Böylece char tipindeki dizi integer tipe dönüştürülmüştür.

“Sayilar.txt” dosyasındaki elemanları integer bir diziye atadıktan sonra kuyruk yapısı 
oluşturulmaya başlanmıştır. Bunun için data ve pointer içeren bir struct oluşturulmuştur.
Kuyruğun başını gösteren root ve sonunu gösteren son pointerına ilk değer olarak “NULL” 
atanmıştır. 

“Sayilar.txt” dosyasında tek bir satır olarak yer alan sayı dizisindeki sayıların ikişer ikişer okunup buradaki değerlerin onlar basamağının 0 gelmesi halinde onlar basamağına 1, sonda tek basamaklı bir eleman olması halinde ise birler basamağına 0 eklenmesi şeklinde kuyruğa atanması amaçlanmıştır. Bunun için Kuyruk adında integer tipinde bir fonksiyon oluşturulmuştur. Yukarıda bahsedilen “sayiDizi” si ve ftell() fonksiyonu ile hesapladığımız boyut parametre olarak oluşturduğumuz fonksiyona gönderilmiştir. 0’dan başlayıp dizimizin boyutuna kadar giden bir for döngüsü açılmıştır. Bu for döngüsündeki atama başlangıçta iki koşula bağlanmıştır. Bu koşul ise for döngüsünde dizi elemanları üzerinde gezinirken kaçıncı indekste olunduğuyla ilgilidir. Bunun bir örnekle anlatılması gerekirse şu şekilde özetlenebilir. “sayiDizi” nin içerisinde sırasıyla 500124000 olsun. Bu değerleri iki basamaklı olacak şekilde bir kuyruğa atmamız gerekiyor. Dizimizin boyutu da ftell() ile hesaplandığında 9 olarak bulundu. İlk indeksten başlayarak for döngüsü ile dizi elemanları üzerinde gezilmeye başlanıldı. 2’ye tam bölünen indeksler ve 1 kalanını veren indeksler ayrı şekilde incelendi. ilk indeks 0 ve 2’ye tam bölünme koşulunu sağlıyor. İlk indekste yer alan eleman ise 0 olma veya olmama durumlarına göre ayrı incelenmiştir. 0 olma durumunda for döngüsü dışında oluşturulan 2 elemanlık dizinin ilk elemanına 10 atanmıştır. 0 olmama durumunda ise “sayiDizi” sinin ilk elemanı 10 ile çarpılıp 2 elemanlık dizinin ilk elemanına atanmıştır. İkinci indeks 1 ve 2 ile bölümünden 1 kalanını veriyor. Bu durumda for döngüsü dışında oluşturulan 2 elemanlık dizinin 2.elemanına “sayiDizi” sinin 1.indeksteki elemanını yani 0 atanacaktır. Daha sonrasında 2 elemanlık dizinin elemanları toplanarak bir sayıya atanacaktır. Elde edilen sayının kuyruğa atanması root’un “NULL” olması veya olmaması koşuluna göre farklılık gösterecektir. Eğer “NULL” ise root için bellekte alan açılıp sayı root’un datasına atanacak, root’un nexti de “NULL” a eşitlenecektir. Eğer “NULL” değilse kuyruk mantığına göre (FIFO) en son eklenenin kuyruğun sonunda olması gerektiğinden son’un nexti için bellekte yeni bir yer oluşturulup oluşturulan yerin datasına sayı  atanacaktır.  Son düğümü artık son’un nexti olacak ve yeni son’un nexti de “NULL” a eşitlenecektir. Bu atama sonrasında Boyut’un 2 ile modunun 1 olması halinde de (yani kuyruğun en sonundaki elemanın tek basamaklı olması durumu) dizinin sonunda 0 varsa sayi=10, dizinin sonunda 0 dışında bir sayı varsa da sayi=sayiDizi[Boyut-1] * 10 ataması yapılacaktır. Bu atama sonrasında tekrardan kuyruk üzerindeki gerekli işlemler yapılarak kuyruğun sonundaki eleman güncellenmiştir. Kuyruk yapısında bağlı liste kullanılarak karmaşıklık açısından daha elverişli bir yapı oluşturulmaya çalışılmış ve aynı zamanda bellek de daha efektif şekilde kullanılmıştır.
printKuyruk() fonksiyonu ise adından da anlaşılacağı üzere kuyruğu yazdırmak için oluşturulmuştur. Geçici bir düğüm(temp) oluşturulmuş ve root temp’e eşitlenmiştir. Temp’in “NULL” olması halinde ekrana “Liste Bos” olmaması halinde de “NULL” görene kadar while döngüsü ile kuyruktaki değerleri ekrana basma işlemi gerçekleştirilmiştir.
Kuyruktaki elemanların ortalamasının hesaplanması için bir fonksiyon oluşturulmuş ve ortalamadan küçük olan elemanların stacke aktarılması işlemine geçilmiştir. Fonksiyon içerisinde toplam ve elemanSayisi değişkenleri oluşturulmuş ve ilk değer olarak 0’a eşitlenmiştir. Liste mantığı ile kuyrukta dolaşılmış böylece toplam ve elemanSayisi son değerlerini almıştır. Ortalama değer toplamın elemanSayisi’na bölünmesiyle bulunmuştur.
Ortalamaya bağlı olarak stack’e atılması gereken elemanlar için öncelikle push() fonksiyonu oluşturulmuştur. Fonksiyon içinde top değeri devamlı olarak güncellenmiştir(Hep en tepedeki eleman olacak şekilde).
Stack yapısında kullanılması için yeni bir struct oluşturulmuştur. Bu yapı oluşturulduktan sonra Stack() fonksiyonunun koduna geçilmiştir. Ortalama değeri bu fonksiyon içerisinde ekrana yazdırılmıştır. Ardından içerisinde geçici bir düğümoluşturulmuş(temp), bu düğüm için bellekte yer açılmış ve temp root’a eşitlenmiştir. Temp “NULL” oluncaya dek kuyruk üzerinde dolaşılmıştır. Stack() fonksiyonu içinde “temp->data” nın kuyruk ortalamasından küçük olması halinde tempin datası stacke pushlanmıştır. Ardından her seferinde tempin bir sonraki düğüme eşitlenmesi işlemi gerçekleştirilmiştir, bu sayede kuyruk üzerinde dolaşılma işlemi tamamlanmış ve gerekli koşulların sağlanması durumunda kuyruk elemanları stacke atılmıştır. Sonrasında ise printStack() fonksiyonu ile stackteki elemanlar ekrana bastırılmıştır. 
Stack elemanlarının ekrana bastırılma işlemini yapan fonksiyondaki önemli nokta çok basit şekilde hem stack elemanlarını ekrana basması hem de stackUzunluğu’nu hesaplamasıdır. Stack uzunluğunun stackteki elemanları diziye aktarmak için bilinmesi gerekmektedir.
Stack yapısının oluşturulması tamamlandıktan sonra stackteki elemanlari diziye çekme işlemine geçilmiştir. DiziyeCekme() isminde bir fonksiyon oluşturulmuştur ve içerisinde nodeS tipinde bir geçici düğüm oluşturulup bellekte alan açıldıktan sonra bu düğüm “top” a eşitlenmiştir. Ardından diziList isminde int tipinde bir pointer oluşturulmuştur. Bu pointer için bellekte “stackUzunluk” u kadar yer açılmıştır. Bu sayede bellek kullanımının da mümkün olan en iyi şekilde olması sağlanmıştır. i<stackUzunluk olacak şekilde bir for döngüsü açılmış ve stackteki elemanlar diziye aktarılmıştır. Sonrasında da tekrar bir for döngüsü ile dizideki elemanlar ekrana basılmıştır. 
Son olarak oluşturulan fonksiyonlar int main() içerisinde çağırılmış ve kodlama işlemi sonlandırılmıştır. 
![Screenshot_28](https://user-images.githubusercontent.com/79109512/174160934-2ec42af1-d397-42b8-a4cb-c93ec3485001.png)
Yukarıdan da görüldüğü gibi 33 bytelık dosya içeriği ekrana bastırılmıştır. Dosya içeriği 533548562364000115356500000245120 ‘ dir. Gerekli işlemler yapılarak(ilk basamağın 0 gelmesi halinde ilk basamağa 1, sonuncu elemanın tek basamaklı olması durumunda ise sonuna 0 eklemek...) bu içerik ikişer ikişer kuyruğa atılmıştır. First In First Out mantığıyla çalışan kuyrukta 53 kuyruk başı 10 kuyruk sonudur. Kuyruk elemanları toplandığında 514 yapmaktadır ve görüldüğü üzere kuyrukta 17 tane sayı vardır. 514/17=30.23 yapar, ekran çıktısı da bize ortalamanın doğru şekilde hesaplandığını göstermektedir. 30’dan küçük olan kuyruk elemanları stacke atılmıştır. Stackin top’ı 10’dur. Diziye çekme işlemi de toptan en alttaki elemana kadar yapılmıştır.

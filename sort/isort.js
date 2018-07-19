
exports.innerSort = function(array, key, is_asc){
    for(var i = 1; i<array.length; i++){
        console.log(i, array[i][key], is_asc);
        
        //「挿入する値」を変数に一時保存する
        var tmp = array[i];
        var j;

        for(j = i-1; j>=0; j--){
            //「挿入する値」が小さい場合、調べた値を１つ後ろへずらす
            if(is_asc && (array[j][key] > tmp[key])){
                array[j+1] = array[j];
            }else if(!is_asc && (array[j][key] < tmp[key])){
                array[j+1] = array[j];
            }else{
                //小さくなければ、ずらす処理を止める
                break;
            }
        }
        //ずらす処理が終わったところに「挿入する値」を入れる
        array[j+1] = tmp;
    }
    for(var i = 0; i<array.length; i++){
        // console.log(i, array[i][key]);
        if(!array[i][key]){
            // console.log('null');
            array.push(array[i]);
            array.shift();
        }
    }    
    return array;
}

//---- test -----
// var ar = [{'key':2}, {'key':10}, {'key':0}, {'key':1}, {'key':6}, {'key':8}];
// console.log(innerSort(ar, 'key', false));

//---- test -----
// var key = 'recipe_time';
// var sorted = exports.innerSort(getSample(), key, true);
// console.log(sorted);

function getSample(){
    return [
        {
            "thumb_url": 'https://www.kyounoryouri.jp/upfile/2004040600241.jpg',
            "recipe_name": 'たことトマトのサラダ',
            "detail_url": 'https://www.kyounoryouri.jp/recipe/2251_たことトマトのサラダ.html',
            "recipe_desc": 'ボリュームたっぷりのサラダは、赤い彩りも綺麗で食欲もそそります。たこの食感もポイントですよ。',
            "heart_num": '10636',
            "recipe_time": '15',
            "recipe_calorie": '160' 
        },{
            "thumb_url": 'https://www.kyounoryouri.jp/upfile/l_1189488233_6215.jpg',
            "recipe_name": '万能！フレンチの素',
            "detail_url": 'https://www.kyounoryouri.jp/recipe/4258_万能！フレンチの素.html',
            "recipe_desc": '包丁も火も使わずに材料を混ぜるだけ。これさえあれば、家庭でも本格的なプロの味が楽しめます。\r\n',
            "heart_num": '6103',
            "recipe_time": null,
            "recipe_calorie": null
        },
        {
            "thumb_url": 'https://www.kyounoryouri.jp/upfile/l_1339554353_8915.jpg',
            "recipe_name": '本格ラタトゥイユ',
            "detail_url": 'https://www.kyounoryouri.jp/recipe/17545_本格ラタトゥイユ.html',
            "recipe_desc": 'ラタトゥイユは「野菜のトマト煮込み」ではないんです！野菜をていねいにしっかり炒めてから煮ることでどの野菜も「主役」の味に仕上がりますよ。',
            "heart_num": '5811',
            "recipe_time": '45',
            "recipe_calorie": '420'
        },
        {
            "thumb_url": 'https://www.kyounoryouri.jp/upfile/l_1242621747_2467.jpg',
            "recipe_name": 'トマトとチキンの煮込み',
            "detail_url": 'https://www.kyounoryouri.jp/recipe/8622_トマトとチキンの煮込み.html',
            "recipe_desc": 'トマト缶と余りがちなキャベツで、手軽なのに味は本格派のうれしい一皿です。',
            "heart_num": '4818',
            "recipe_time": '20',
            "recipe_calorie": '330'
        },
        {
            "thumb_url": 'https://www.kyounoryouri.jp/upfile/2001090840141.jpg',
            "recipe_name": 'なすのグラタン',
            "detail_url": 'https://www.kyounoryouri.jp/recipe/535_なすのグラタン.html',
            "recipe_desc": 'なすは、トマトソースとチーズの相性抜群！ソースさえつくりおきしておけば、とっても簡単につくれますよ。',
            "heart_num": '3933',
            "recipe_time": '30',
            "recipe_calorie": '220'
        },
        {
            "thumb_url": 'https://www.kyounoryouri.jp/upfile/2002070490241.jpg',
            "recipe_name": 'なすとトマトのパスタ',
            "detail_url": 'https://www.kyounoryouri.jp/recipe/981_なすとトマトのパスタ.html',
            "recipe_desc": 'トマトソースを使ったなすのパスタ。なすの皮はソースの色を悪くするので、しま目にむいておきます。',
            "heart_num": '3596',
            "recipe_time": '20',
            "recipe_calorie": '500'
        },
        {
            "thumb_url": 'https://www.kyounoryouri.jp/upfile/l_1221118117_1383.jpg',
            "recipe_name": 'ピッツァ・マルゲリータ',
            "detail_url": 'https://www.kyounoryouri.jp/recipe/6931_ピッツァ・マルゲリータ.html',
            "recipe_desc": '本格的なピッツァが、魚焼きグリルを利用すれば、家庭で再現可能に。マルゲリータをマスターしましょう。',
            "heart_num": '3397',
            "recipe_time": '60',
            "recipe_calorie": '460'
        },
        {
            "thumb_url": 'https://www.kyounoryouri.jp/upfile/l_1334213210_1990.jpg',
            "recipe_name": 'トマトチキンカレー',
            "detail_url": 'https://www.kyounoryouri.jp/recipe/15539_トマトチキンカレー.html',
            "recipe_desc": 'トマトのうまみがギュッと詰まったカレーです。トマトは完熟を使うのがポイント。市販のカレー粉でつくれる、さらりとしたカレーです。',
            "heart_num": '3381',
            "recipe_time": '60',
            "recipe_calorie": '700'
        },
        {
            "thumb_url": 'https://www.kyounoryouri.jp/upfile/2002090390141.jpg',
            "recipe_name": '卵とトマトの炒め物',
            "detail_url": 'https://www.kyounoryouri.jp/recipe/1067_卵とトマトの炒め物.html',
            "recipe_desc": '北京では一番ポピュラーな炒め物。トマトの水分を上手に保ちながら火を通すのがポイントです。',
            "heart_num": '3009',
            "recipe_time": '15',
            "recipe_calorie": '170'
        }
    ]
}


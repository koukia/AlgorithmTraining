function innerSort(array, key, is_asc){
    for(let i = 1; i<array.length; i++){
        console.log(i, array[i][key], is_asc);
        
        //「挿入する値」を変数に一時保存する
        let tmp = array[i];
        let j;

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
    for(let i = 0; i<array.length; i++){
        // console.log(i, array[i][key]);
        if(!array[i][key]){
            // console.log('null');
            array.push(array[i]);
            array.shift();
        }
    }    
    return array;
}

function testInnerSort(){
    
    let data = [{key:-100, id:1},{key:30, id:2},{key:10, id:3}];
    let i, is_passed=true, sorted_data;

    sorted_data = innerSort(data, "key", true);
    console.log(sorted_data);
    for (i=0;i<sorted_data.length-1;i++){
        if (sorted_data[i]["key"] > sorted_data[i+1]["key"])
            is_passed = false;
    }
    if (is_passed)
        console.log("Cace 1 is passed.");
    else
       console.log("Cace 1 is failed...");

    sorted_data = innerSort(data, "key", false)
    console.log(sorted_data);
    for (i=0;i<sorted_data.length-1;i++){
        if (sorted_data[i]["key"] < sorted_data[i+1]["key"])
            is_passed = false;
    }
    if (is_passed)
        console.log("Cace 1 is passed.");
    else
       console.log("Cace 1 is failed...");

}

testInnerSort();

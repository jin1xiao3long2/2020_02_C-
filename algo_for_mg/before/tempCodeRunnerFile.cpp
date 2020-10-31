var resultSet = undefined;

    //创建和初始化地图函数：
    function initMap(){
        createMap();//创建地图
        setMapEvent();//设置地图事件
        addMapControl();//向地图添加控件
        addMarker();//向地图中添加marker
    }
    
    //创建地图函数：
    function createMap(){
        var map = new BMap.Map("dituContent");//在百度地图容器中创建一个地图
        var point = new BMap.Point(104.00727,30.562394);//定义一个中心点坐标
        map.centerAndZoom(point,18);//设定地图的中心点和坐标并将地图显示在地图容器中
        window.map = map;//将map变量存储在全局
    }
    
    //地图事件设置函数：
    function setMapEvent(){
        map.enableDragging();//启用地图拖拽事件，默认启用(可不写)
        map.enableScrollWheelZoom();//启用地图滚轮放大缩小
        map.enableDoubleClickZoom();//启用鼠标双击放大，默认启用(可不写)
        map.enableKeyboard();//启用键盘上下左右键移动地图
    }
    
    //地图控件添加函数：
    function addMapControl(){
        //向地图中添加缩放控件
	var ctrl_nav = new BMap.NavigationControl({anchor:BMAP_ANCHOR_TOP_LEFT,type:BMAP_NAVIGATION_CONTROL_LARGE});
	map.addControl(ctrl_nav);
        //向地图中添加缩略图控件
	var ctrl_ove = new BMap.OverviewMapControl({anchor:BMAP_ANCHOR_BOTTOM_RIGHT,isOpen:1});
	map.addControl(ctrl_ove);
        //向地图中添加比例尺控件
	var ctrl_sca = new BMap.ScaleControl({anchor:BMAP_ANCHOR_BOTTOM_LEFT});
	map.addControl(ctrl_sca);
    }
    
    //标注点数组
    var markerArr = [{title:"图书馆前草坪",content:"我的备注",point:"104.007499|30.562425",isOpen:0,icon:{w:21,h:21,l:0,t:0,x:6,lb:5}}
		 ];
    //创建marker
    function addMarker(){
        for(var i=0;i<markerArr.length;i++){
            var json = markerArr[i];
            var p0 = json.point.split("|")[0];
            var p1 = json.point.split("|")[1];
            var point = new BMap.Point(p0,p1);
			var iconImg = createIcon(json.icon);
		
            var marker = new BMap.Marker(point,{icon:iconImg});
			var iw = createInfoWindow(i);
			var label = new BMap.Label(json.title,{"offset":new BMap.Size(json.icon.lb-json.icon.x+10,-20)});
			marker.setLabel(label);
            map.addOverlay(marker);
            label.setStyle({
                        borderColor:"#808080",
                        color:"#333",
                        cursor:"pointer"
            });
			
			(function(){
				var index = i;
				var _iw = createInfoWindow(i);
				var _marker = marker;
				_marker.addEventListener("click",function(){
				    this.openInfoWindow(_iw);
			    });
			    _iw.addEventListener("open",function(){
				    _marker.getLabel().hide();
			    })
			    _iw.addEventListener("close",function(){
				    _marker.getLabel().show();
			    })
				label.addEventListener("click",function(){
				    _marker.openInfoWindow(_iw);
			    })
				if(!!json.isOpen){
					label.hide();
					_marker.openInfoWindow(_iw);
				}
			})()
        }
    }
    //创建InfoWindow
    function createInfoWindow(i){
        var json = markerArr[i];
        var iw = new BMap.InfoWindow("<b class='iw_poi_title' title='" + json.title + "'>" + json.title + "</b><div class='iw_poi_content'>"+json.content+"</div>");
        return iw;
    }
    //创建一个Icon
    function createIcon(json){
        var icon = new BMap.Icon("marker.png", new BMap.Size(json.w,json.h),{imageOffset: new BMap.Size(-json.l,-json.t),infoWindowOffset:new BMap.Size(json.lb+5,1),offset:new BMap.Size(json.x,json.h)})
        return icon;
    }


/*-------------------------------------交互函数开始---------------------------------------------*/
    function createMyInfoWindow(name, content){
        var iw = new BMap.InfoWindow("<b class='iw_poi_title' title='" + name + "'>" + name + "</b><div class='iw_poi_content'>"+ contentChange(content)+"</div>");
        return iw;
    }
    function createMyIcon(png){
        var icon = new BMap.Icon(png,new BMap.Size(21, 21),{imageOffset: new BMap.Size(0, 0), infoWindowOffset:new BMap.Size(10,1 ),offset: new BMap.Size(6,21)})
        return icon;
    }

function addMydetailMarker(name, content, type, lon, lat, radius){
	
	var iconImg = undefined;
	if(type == "hospital")
	{
		iconImg = createMyIcon("hospital.png");
	}else if(type == "rescue")
	{
		iconImg = createMyIcon("rescue.png");
	}else
	{
		iconImg = createMyIcon("marker.png");
	}	
	var point = new BMap.Point(lon, lat);
	var circle = undefined;
	var marker = new BMap.Marker(point,{icon:iconImg});
		var iw = createMyInfoWindow(name, content);
		var label = new BMap.Label(name,{"offset":new BMap.Size(5-6+10,-20)});
		marker.setLabel(label);
	map.addOverlay(marker);

	label.setStyle({
                        borderColor:"#808080",
                        color:"#333",
                        cursor:"pointer"
            });
			
			(function(){
				var _iw = createMyInfoWindow(name, content);
				var _marker = marker;
				_marker.addEventListener("click",function(){
				    this.openInfoWindow(_iw);
			    });
			    _iw.addEventListener("open",function(){
				    _marker.getLabel().hide();
					if(radius > 0)
					{
						circle = new BMap.Circle(point, 10000, {fillColor:"#0F0", strokeColor: "#000", strokeWeight: 1 ,fillOpacity: 0.08, strokeOpacity: 0.9,enableEditing:false});
        					circle.enableMassClear();
						map.addOverlay(circle);
					}
			    })
			    _iw.addEventListener("close",function(){
				    _marker.getLabel().show();
					map.removeOverlay(circle);
			    })
				label.addEventListener("click",function(){
				    _marker.openInfoWindow(_iw);
					
			    })
				if(!!markerArr[0].isOpen){
					label.hide();
					_marker.openInfoWindow(_iw);
					
				}
			})()
}

function getRecord(queryKey)
{
	//console.log("queryKey is  " + queryKey);
	var allOverlay = map.getOverlays();
	for(var i = 0; i < allOverlay.length; i++)
		 map.removeOverlay(allOverlay[i]);
	var url = "back.jsp?key_value="+queryKey;
	$.post(url,function(json){
		//console.log("返回的	数据是:  "+JSON.stringify(json));
		resultSet = json;
		addMarkers(json);
	});
}

function addMarkers(json){
    var list = json.aaData;
    //console.log("查询出来的数据有: "+list.length +"个");
    for(var i = 0; i < list.length; i++){
          addMyMarker(list[i]);
    }
}

function addMyMarker(json)
{
	addMydetailMarker(json.name, json.content, json.type, json.lon, json.lat, json.radius);
	
}
/*-------------------------------------交互函数结束---------------------------------------------*/
function contentChange(content)
{
	var pos = new Array();
	for(var i = 0; i < content.length; i++)
	{
		if(content[i] == '.')
			pos.push(i);
		//console.log(pos[i]);
	}
	var str = new Array();
	for(var i = 0; i < str.length; i++)
	{
		str.push(content.substring(pos[i]-1,pos[i+1]-1));
		//console.log(str[i]);
	}
	var newContent = "";
	for(var i = 0; i < str.length; i++)
	{
		newContent.concat(str[i]);
		newContent.concat("<br>");
	}
	return newContent;
}    
    initMap();//创建和初始化地图
    addMydetailMarker("草坪","test111", "hospital", 104.021,30.666 ,1);
    getRecord("");

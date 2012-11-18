<%@ Page Language="C#" AutoEventWireup="true"  CodeFile="main.aspx.cs" Inherits="_Default" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>无标题页</title>
   <script type="text/javascript" src="http://maps.google.com/maps/api/js?sensor=true"></script>
 
    <script type="text/javascript">
        var poly, map;
        var i = 0;
        function initialize() {
            var myOptions = {
                zoom:5,
                center: new google.maps.LatLng(32.090145, 118.788034),
                mapTypeControl: true,
                mapTypeControlOptions: { style: google.maps.MapTypeControlStyle.DROPDOWN_MENU },
                navigationControl: true,
                navigationControlOptions: { style: google.maps.NavigationControlStyle.SMALL },
                mapTypeId: google.maps.MapTypeId.ROADMAP
            };
           map = new google.maps.Map(document.getElementById("map_canvas"), myOptions);
            
           var polyOptions = { strokeColor: '#FF0000', strokeOpacity: 1.0, strokeWeight: 3 };
           poly = new google.maps.Polyline(polyOptions);
            poly.setMap(map);
          

            var shiType = '<%=shiJian %>';
            if (shiType == '1') {
                var strPP = '<%=strP %>'.split(",");
                setcarline(strPP);  //导航点
            }
            if (shiType == '2') {
                var strPP = '<%=strP %>'.split("|");
                var myLL=new google.maps.LatLng(strPP[0], strPP[1]);
                drawCircle(myLL);   //行政单位点
            }
        }
        function doClick(num) {
             var isSee = document.getElementById("div" + num).style.display;
             if (isSee == "none") {
                 document.getElementById("div" + num).style.display = "block";
             }
             else {
                 document.getElementById("div" + num).style.display = "none";
             }
         }
         var p1, p2;
         function doClickDist(event) {
             var path = poly.getPath();
             var nowPoint = event.latLng;
             path.push(nowPoint);
             i++;
             if (i == 1) {
                 p1 = event.latLng;
                 alert(event.latLng.lat() + "|" + event.latLng.lng());
               }
             var marker = new google.maps.Marker({
                 position: event.latLng,
                 title: '#' + path.getLength(),
                 map: map
             });
             if (i == 2) {
                 p2 = event.latLng;
                 var latR1 = p1.lat() * (Math.PI/ 180);
                 var latR2 = p2.lat()* (Math.PI / 180);
                 var latR = latR1 - latR2;
                 var lngR = p1.lng() * (Math.PI / 180) - p2.lng() * (Math.PI / 180);
                 var f = 2 * Math.asin(Math.sqrt(Math.pow(Math.sin(latR / 2), 2) +
                 Math.cos(latR1) * Math.cos(latR2) * Math.pow(Math.sin(lngR / 2), 2)));
                 f = f * 6378.137;
                 f = Math.round(f*10000)/10000;
                 var infowindow=new google.maps.InfoWindow({content:"这两地相距"+f+"公里",position:p2});
                 infowindow.open(map);
                 i = 0;
                   }
           map.setCenter(nowPoint);
           }
         function setcarline(arrStr) {
             var p = 0;
             try {
                 var points = [];
                 if ((arrStr != null) && (arrStr.length > 0)) {
                      for (var j = 0; j < arrStr.length - 1; j++) {
                         var temp = arrStr[j].split("|");
                            if (temp.length == 2) {
                               points[p] = new  google.maps.LatLng(temp[0], temp[1]);
                               p++;
                         }
                     }
                 //    var polyline2 = new GPloyline(points, "#ff0000", 6);
                 //    map.addOverlay(polyline2);

                     var polyline2 = new google.maps.Polyline({path:points, strokeColor:"#ff0000",strokeWeight:3 });
                     polyline2.setMap(map);
                 }
             } catch (e) {
             alert(e.name+":"+e.message);
              }
     }
     function doLatLng() {
       
         var a = document.getElementById("Text1").value;
         var b = document.getElementById("Text2").value;
         var myLatLng = new google.maps.LatLng(a, b);
        // var img = "~/pic/icon.gif";
         alert(a + "|" + b);

         var myMarker = new google.maps.Marker({ position: myLatLng, map: map});
         map.setCenter(myLatlng);
         map.setZoom(3);
     }
     function drawCircle(centerLatLng) {
        var populationOptions = { strokeColor: "#FF0000", strokeOpacity: 0.8, strokeWeight: 2, fillColor: "#FF0000", fillOpacity: 0.35,
             center: centerLatLng, radius: 10000
        };
        var marker = new google.maps.Marker({ position: centerLatLng, map: map });  //记得加图标

        var cityCircle = new google.maps.Circle(populationOptions);  //***************************
        cityCircle.setMap(map);
        map.setCenter(centerLatLng);
        map.setZoom(9);

    }
    function doClickJuLi() {
        google.maps.event.addListener(map, 'click', doClickDist);
    }
      
        
    </script>
    <style type="text/css">
        #Text1
        {
            width: 55px;
            margin-left: 0px;
            height: 20px;
        }
        a
        {
          text-decoration:none; 	
       }
       
       div{ height: 44px;
            width: 348px;
            
        }
        
            
          
        #Text2
        {
            width: 62px;
            height: 21px;
            margin-left: 8px;
        }
    </style>
</head>
<body onload="initialize()">
    <form id="form1" runat="server">
    <p>
        &nbsp;</p>
    <p>
        <input id="Button1" 
            style="background-image: url('pic/back1.jpg'); width: 82px; height: 23px; margin-left: 10px;" 
            type="button" value=" 图形功能" onclick="doClick(1)" />&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; </p>
    <div id="map_canvas" 
        style="position: absolute;display:block; left: 417px; width: 743px; height: 600px; top: 2px">
        <asp:SqlDataSource ID="SqlDataSource1" runat="server"></asp:SqlDataSource>
    </div>
    <div id="div1" 
        style="height: 90px; width: 247px; margin-left: 34px;" >
        <a href="javascript:void(0)"  onclick="doClick('1_1')">按行政单位查询</a>
        <div id="div1_1" 
           style="width: 239px; height: 25px; clip: rect(auto, auto, auto, 20px); "  
            >
&nbsp;<asp:TextBox ID="TextBox1" runat="server" Width="110px" Height="25px"></asp:TextBox>
            &nbsp;&nbsp;
            <asp:Button ID="Button3" runat="server" BorderStyle="Outset" Height="19px" 
                Text="查询" Width="65px" onclick="Button3_Click" />
        </div>
        <br />
        <a href="javascript:void(0)"  onclick="doClickCharac()">符号化</a><br />
        <a href="javascript:void(0)"  onclick="doClickJuLi()">距离测算</a><br />
    </div>
    <p>
        &nbsp;&nbsp;&nbsp;<input id="Button2" 
            style="background-image: url('pic/back2.jpg'); width: 82px; height: 24px; margin-left: 0px;" 
            type="button" value="定位功能" onclick="doClick(2)" /> </p>
        
        <div id="div2" style="width: 360px; height: 191px; margin-left: 35px;">
          <a href="javascript:void(0)"  onclick="doClick('2_1')">按坐标查询</a><br />
            <div id="div2_1">
                纬度:&nbsp;<input id="Text1" type="text" />&nbsp; 经度：<input id="Text2" 
                    type="text" />&nbsp;&nbsp;
                <input id="Button4" type="button" value="定位" onclick="doLatLng()" /></div>
            <br />
            <a href="javascript:void(0)"  onclick="doClick('2_2')">按名称定位</a><div 
                id="div2_2" 
                style="width: 292px; height: 25px; clip: rect(auto, auto, auto, 20px); "  > 
                 <asp:TextBox ID="TextBox2_3" runat="server" Width="110px" Height="25px"></asp:TextBox>
                  &nbsp;&nbsp;
                  <asp:Button ID="Button5" runat="server" BorderStyle="Outset" Height="19px" Text="查询" Width="65px" /></div><br />
                 <a href="javascript:void(0)"  onclick="doClick('2_3')">驾驶导航</a>
                <div id="div2_3">
                起始位置:<asp:TextBox ID="TextBox2_4" runat="server" Width="54px" Height="28px" 
            style="margin-left: 1px; margin-top: 8px"></asp:TextBox>目标位置 
                   <asp:TextBox ID="TextBox2_5" runat="server" Width="45px" Height="27px" 
            style="margin-left: 0px"></asp:TextBox>&nbsp;&nbsp;
        <asp:Button ID="Button6" runat="server" BorderStyle="Outset" Height="16px" Text="导航" 
                       Width="65px" onclick="Button6_Click"  />
            </div> <br />  
           </div>
    <br />
        
</form>
    <p>
        <input id="Button7" onclick="doClick(3)" 
            style="background-image: url('/pic/back2.jpg'); width: 82px; height: 24px; margin-left: 20px;" 
            type="button" value="车辆管理" /></p>
    <div id="div3" >
        &nbsp;&nbsp;
        点击 <a href="carManage.aspx" 
            style="text-decoration:underline blink; font-family: 幼圆; font-size: large; font-weight: bold; font-style: italic; color: #FF0000;">这里</a> 进行车辆管理
        </div>
    <p>
        &nbsp;</p>
    <p>
        &nbsp;&nbsp;</p>
</body>
</html>

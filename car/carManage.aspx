<%@ Page Language="C#" AutoEventWireup="true" CodeFile="carManage.aspx.cs" Inherits="carManage" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>车辆管理页面</title>
 <script type="text/javascript" src="http://maps.google.com/maps/api/js?sensor=true"></script>
     <script type="text/javascript">
        var map;
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
       
         var  posColl = '<%=posCol %>';
         if (posColl.length != 0) {
             alert("111111");
             var arrStr = posColl.split(",");
             var p = 0;
             try {
                 var points = [];
                 if ((arrStr != null) && (arrStr.length > 0)) 
                 {
                     for (var j = 0; j < arrStr.length - 1; j++) 
                     {
                         var temp = arrStr[j].split("|");
                         if (temp.length == 2) 
                         {
                             points[p] = new google.maps.LatLng(temp[0], temp[1]);
                             p++;
                         }
                     }
                 }
                 setCarRun(points);

             } catch (e) {
                 alert(e.name + ":" + e.message);
                }
          }
       } 
        
        var i=0;
        
       function setCarRun(pointCollection){
           alert("***");
           setTimeout(3000,'setCarRun(pointCollection)');
           var myLatLng=new google.maps.LatLng(pointCollection[0]);
           var myMarker=new google.maps.Marker({position:myLatLng,map:map});
           i++;
           if(i>=pointCollection.length){
             i=0;
            }
        }  
  </script>
</head>
<body onload="initialize()">
  <form id="form1" runat="server">
<p>
    车辆跟踪，请输入车牌号：</p>
<p>
    <asp:SqlDataSource ID="SqlDataSource1" runat="server" 
        ConnectionString="<%$ ConnectionStrings:dbCarConnectionString %>" 
        SelectCommand="SELECT * FROM [tb_carPos]"></asp:SqlDataSource>
    <asp:TextBox ID="TextBox1" runat="server" Height="31px"></asp:TextBox>
    <asp:Button ID="Button1" runat="server" BackColor="#FFCC66" 
        BorderStyle="Outset" style="margin-left: 19px" Text="查询" Width="79px" 
        onclick="Button1_Click" />
</p>
<div id="map_canvas" style="height: 700px; margin-left: 255px; width: 847px;">
</div>
</form>
</body>
</html>


